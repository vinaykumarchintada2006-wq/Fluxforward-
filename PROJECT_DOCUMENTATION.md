# Flux Forward: Project Report & Technical Blueprint
**Smart India Hackathon 2026** | **Problem Statement ID:** 26212
---
## Executive Summary
Rapid urbanization poses major municipal challenges regarding unsegregated waste dumping and poor public hand hygiene. **Flux Forward** is an autonomous municipal pod that performs automated mechanical waste segregation at source while dispensing contactless hand sanitizer to encourage civic participation.
---
## System Methodology
1. **Detection Stage:** The user drops waste into the entry hopper. An entry IR sensor detects object placement and triggers the scanning cycle.
2. **Analysis Stage:**
   * An **LJ12A3 inductive sensor** scans for metallic conductivity.
   * A **capacitive moisture sensor** reads electrolytic moisture content without corrosive metal degradation.
3. **Sorting Stage:**
   * **Metal detected:** Servo flap drives to 45 degrees (Chute A: Metal Recyclables).
   * **High moisture (>2300 ADC):** Servo flap drives to 135 degrees (Chute B: Organic/Compost).
   * **Low moisture / Non-metal:** Servo flap drops through 90 degrees (Chute C: Dry Plastics & Paper).
4. **Community Sanitization Stage:** An external ultrasonic misting array detects hands within 10 cm and dispenses an 800 ms atomized sanitizing spray.
---
## Bill of Materials (BOM)

| Component | Quantity | Purpose | Approximate Cost (INR) |
| :--- | :--- | :--- | :--- |
| **ESP32 DevKit V1** | 1 | Edge compute and control controller | ₹450 |
| **LJ12A3-4-Z/BX Sensor** | 1 | Inductive metal proximity detection | ₹220 |
| **Capacitive Moisture v1.2** | 1 | Non-corrosive organic matter sensing | ₹110 |
| **MG996R Metal Servo** | 1 | Heavy-duty flap diversion actuator | ₹350 |
| **HC-SR04 Ultrasonic** | 1 | Contactless hand distance measurement | ₹80 |
| **5V Relay Module** | 1 | High-current mist pump switching | ₹65 |
| **12V Mist Pump & Nozzle** | 1 | Sanitizer aerosol dispersion | ₹400 |
| **LM2596 Buck Converter** | 1 | Regulated step-down power unit | ₹95 |
| **Total Prototype Cost** |  |  | **~ ₹1,770** |

---
## Scalability & Future Roadmap
* **Edge AI Integration:** Adding an ESP32-CAM running a lightweight MobileNet model to detect single-use plastics and biomedical materials.
* **LoRaWAN / GSM Telemetry:** Real-time bin level reporting to municipal command centres when fill capacity reaches 90%.
