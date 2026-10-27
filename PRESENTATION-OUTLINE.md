# Presentation Outline — Smart Garage Automation and Vehicle Counter

Designed for a 16-slide Gamma presentation for students aged 10–16.

1. **Cover:** Smart Garage Automation and Vehicle Counter — “Detect it. Count it. Open the gate.”
2. **Introduction:** What is a smart garage?
3. **Objectives:** Detection, counting, automated movement, and serial feedback.
4. **Components:** Arduino Uno, HC-SR04, SG90, wires, USB, and miniature gate.
5. **Arduino Uno:** The brain of the system.
6. **Ultrasonic Sensor:** How echo timing estimates distance.
7. **SG90 Servo:** Commanded 0° closed and 90° open positions.
8. **Wiring:** HC-SR04 TRIG D7, ECHO D8; servo signal D9.
9. **Working Process:** Measure → compare with threshold → count → open → close.
10. **Counter Logic:** `totalCars` and `carDetected`.
11. **Code Walkthrough:** Distance measurement, detection condition, servo commands.
12. **Serial Monitor:** Example output and live event reporting.
13. **Debugging Journey:** COM-port error, servo testing, ultrasonic testing, repeated counts.
14. **Benefits and Limitations:** Educational value and prototype boundaries.
15. **Future Scope:** LCD, exit sensor, ESP32 dashboard, occupancy limit, safety improvements.
16. **Conclusion:** What was learned, thank-you, and questions.

**Presentation accuracy note:** The current hardware has one ultrasonic sensor and one servo. It counts detection events that simulate vehicles; it cannot independently verify a unique vehicle or tell entry from exit.
