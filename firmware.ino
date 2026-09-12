#include <ESP32Servo.h>

// --- Pin Definitions ---
const int PIN_IR_ENTRY       = 34; // Hopper input detection (Active LOW)
const int PIN_INDUCTIVE_PROX = 35; // LJ12A3 metal sensor (Digital HIGH when metal)
const int PIN_MOISTURE_ADC   = 32; // Soil moisture sensor analog pin
const int PIN_ULTRASONIC_TRIG= 25; // Sanitizer mist trigger
const int PIN_ULTRASONIC_ECHO= 26; // Sanitizer echo
const int PIN_PUMP_RELAY     = 27; // Sanitizer atomization pump relay
const int PIN_SERVO_FLAP     = 13; // Sorting mechanism flap servo

// --- Operational Parameters ---
const int MOISTURE_THRESHOLD = 2300; // Calibrated boundary: >2300 is wet/organic
const int SANITIZER_RANGE_CM = 10;   // Distance threshold for hand misting

Servo flapServo;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_IR_ENTRY, INPUT);
  pinMode(PIN_INDUCTIVE_PROX, INPUT);
  pinMode(PIN_MOISTURE_ADC, INPUT);

  pinMode(PIN_ULTRASONIC_TRIG, OUTPUT);
  pinMode(PIN_ULTRASONIC_ECHO, INPUT);
  pinMode(PIN_PUMP_RELAY, OUTPUT);
  digitalWrite(PIN_PUMP_RELAY, LOW);

  flapServo.attach(PIN_SERVO_FLAP);
  flapServo.write(90); // 90 deg: Neutral resting position

  Serial.println("[SYSTEM ONLINE] Flux Forward Automated Hub initialized.");
}

void loop() {
  checkWasteSegregation();
  checkSanitizationPod();
  delay(100);
}

void checkWasteSegregation() {
  if (digitalRead(PIN_IR_ENTRY) == LOW) {
    Serial.println("[EVENT] Waste detected in hopper. Initiating scanning sequence...");
    delay(500); // Wait for waste to settle on sensor bed

    bool isMetal = (digitalRead(PIN_INDUCTIVE_PROX) == HIGH);
    int moistureValue = analogRead(PIN_MOISTURE_ADC);

    Serial.print("[METRICS] Metal: "); Serial.print(isMetal);
    Serial.print(" | Moisture ADC: "); Serial.println(moistureValue);

    if (isMetal) {
      Serial.println("[ACTION] Diverting -> Metallic Waste Bin");
      flapServo.write(45);
    } else if (moistureValue > MOISTURE_THRESHOLD) {
      Serial.println("[ACTION] Diverting -> Organic / Wet Waste Bin");
      flapServo.write(135);
    } else {
      Serial.println("[ACTION] Diverting -> Dry / Recyclable Waste Bin");
      flapServo.write(90);
    }

    delay(2500); // Allow physical clearance of waste
    flapServo.write(90); // Reset flap to resting baseline
  }
}

void checkSanitizationPod() {
  digitalWrite(PIN_ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_ULTRASONIC_TRIG, LOW);

  long duration = pulseIn(PIN_ULTRASONIC_ECHO, HIGH, 25000);
  float distance = (duration * 0.0343) / 2.0;

  if (distance > 0 && distance <= SANITIZER_RANGE_CM) {
    Serial.println("[SANITIZER] User hand detected. Dispensing mist spray...");
    digitalWrite(PIN_PUMP_RELAY, HIGH);
    delay(800); // Mist duration
    digitalWrite(PIN_PUMP_RELAY, LOW);
    delay(1500); // Debounce cooldown
  }
}
