# Flux Forward: Smart Automated Waste Segregation & Community Sanitization Pod

An automated, sensor-driven waste segregation and public sanitation system developed for the **Smart India Hackathon 2026** (Problem Statement ID: 26212).

---

## 📌 Project Overview
* **Theme:** Clean and Green Technology
* **Category:** Hardware
* **Team Name:** Flux Forward

The **Smart Automated Waste Segregation and Community Sanitization Pod** is designed to eliminate mixed waste directly at the source. Using sensor arrays and microcontrollers, the unit automatically identifies and routes discarded waste into separate compartments while maintaining public hygiene via automated disinfectant misters.

---

## ⚙️ How It Works
1. **Disposal:** The user drops waste into the intake chute.
2. **Identification:** Sensors detect material properties (metal, moisture, proximity).
3. **Automated Sorting:** Servo actuators route the item into **Dry**, **Wet**, or **Metallic** compartments.
4. **Cloud Telemetry:** Fill-level data transmits to municipal dashboards, alerting workers only when bins reach capacity.

---

## 🛠️ Hardware & Technical Architecture
* **Microcontroller:** ESP32 / Arduino (Core logic, Wi-Fi/Cloud communication)
* **Detection Array:**
  * Inductive Proximity Sensor (Metal detection)
  * Moisture Sensor (Wet vs. dry separation)
  * Ultrasonic Sensors (Fill-level and proximity measurement)
* **Actuators:** Servo motors controlling mechanical redirection flaps
* **Sanitization:** Automated misting system with disinfectant spray triggers
* **Dashboard / IoT:** Real-time monitoring portal for municipal route optimization

---

## 🌍 Key Impact & Benefits
* **Environmental:** Prevents mixed-waste contamination and diverts recyclable material from landfills.
* **Social Safety:** Eliminates manual waste handling, safeguarding sanitation workers from toxic and hazardous contact.
* **Operational Efficiency:** On-demand municipal collection routes based on real-time bin status, reducing vehicle fuel and labor costs.
* 
