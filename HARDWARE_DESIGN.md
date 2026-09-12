# Flux Forward: Hardware & Mechanical Specifications
## 1. System Pin Mapping Table

| Component Name | Pin Identifier | ESP32 GPIO | Operating Voltage | Functionality |
| :--- | :--- | :--- | :--- | :--- |
| **Infrared Proximity** | Digital OUT | GPIO 34 | 5.0V | Detects insertion of waste in the entry chute |
| **Inductive Sensor (LJ12A3)** | Signal OUT | GPIO 35 | 6.0V - 12.0V | Detects ferrous and non-ferrous metals |
| **Capacitive Moisture Sensor** | Analog OUT | GPIO 32 | 3.3V | Measures moisture content of incoming refuse |
| **HC-SR04 Ultrasonic** | Trigger Pin | GPIO 25 | 5.0V | Emits sonic ping for sanitizer activation |
| **HC-SR04 Ultrasonic** | Echo Pin | GPIO 26 | 5.0V (Divided) | Level-shifted to protect 3.3V GPIO |
| **Relay Driver Module** | Control IN | GPIO 27 | 5.0V | Switches 12V atomizer mist pump on/off |
| **High-Torque Servo (MG996R)** | PWM Line | GPIO 13 | 5.0V - 6.0V | Drives 3-way diverter mechanical flap |

---
## 2. Power Distribution Network
* **Primary Source:** 12V 3A DC regulated power adapter or sealed battery.
* **12V Rail:** Supplies direct power to the inductive proximity sensor and the sanitization pump.
* **Buck Converter 1 (LM2596):** Converts 12V -> 5V (3A max) to power the ESP32 `VIN` pin, sensor VCC lines, and servo motor.
* **Protection:** 1N4007 flyback diode placed across inductive pump load to suppress voltage spikes.
---
## 3. Circuit Schematics Flow
