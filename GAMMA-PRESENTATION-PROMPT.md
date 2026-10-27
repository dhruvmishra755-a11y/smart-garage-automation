# Gamma AI Prompt — 16-Slide Smart Garage Presentation

Copy the prompt below into Gamma to generate a beginner-friendly presentation for students aged 10–16.

---

Create **exactly 16 slides** for a presentation titled **“Smart Garage Automation and Vehicle Counter”**. The audience is students aged 10–16 who are new to Arduino and robotics.

Use simple English, short explanations, large readable text, realistic component images, labelled diagrams, flowcharts, and a premium STEM visual style. Use a dark navy and charcoal background with cyan, electric-blue, white, and subtle pink accents. Use these emojis where appropriate: 🚗 📡 🚧 🔢 ✅. Avoid overcrowded slides, complicated jargon, invented test results, and childish clip art.

The project uses an **Arduino Uno, one HC-SR04 ultrasonic sensor, and one SG90 positional servo**. HC-SR04 TRIG connects to D7, ECHO to D8, VCC to 5V, and GND to GND. SG90 orange signal connects to D9, red to a suitable 5V supply, and brown to GND. The distance threshold is 15 cm. The code counts a new detection event, commands the servo to 90°, and commands it back to 0° after 3 seconds. The counter is shown through the Serial Monitor at 9600 baud. The program tracks a detection state to avoid repeated counting during one continuous detection.

**Technical honesty:** The ultrasonic sensor detects objects, not specifically cars. The present one-sensor version counts detection events that simulate vehicles; it cannot verify a unique car, determine entry versus exit, or confirm a complete crossing. The count resets after an Arduino restart. This is a miniature educational prototype, not a safety-rated real-garage controller. Mark future improvements as proposed, not already implemented.

### Slide plan
1. **Cover:** Smart Garage Automation and Vehicle Counter — “Detect it. Count it. Open the gate.” Leave placeholders for student, school/university, and teacher.
2. **Introduction:** What is a smart garage? Compare a manual gate with an automatic miniature gate.
3. **Project Goals:** Detect an object, count a new detection, open the gate, close after three seconds, show events.
4. **Components:** Arduino Uno, HC-SR04, SG90, jumper wires, USB cable, and a lightweight cardboard gate.
5. **Arduino Uno:** Explain the controller as the brain that follows program instructions.
6. **Ultrasonic Sensor:** Explain sound waves, echo, distance calculation, and the 15 cm threshold.
7. **SG90 Servo:** Explain its commanded 0° closed and 90° open positions; do not call it a continuous-rotation motor.
8. **Wiring:** Show the exact pin connections: TRIG D7, ECHO D8, servo signal D9, sensor VCC 5V, all grounds connected.
9. **How It Works:** Start → measure distance → compare with 15 cm → count → open → close after three seconds.
10. **Counter Logic:** Explain `totalCars`, `carDetected`, and why state tracking helps prevent repeated counts.
11. **Inside the Code:** Explain `getDistance()`, `totalCars++`, and `gateServo.write(90)` / `gateServo.write(0)` with small code cards.
12. **Serial Monitor:** Show an illustrative terminal with “CAR PASSED #1”, total detection events, and gate status. State that example output is illustrative.
13. **Debugging Journey:** Explain the COM-port access-denied error, standalone servo testing, standalone ultrasonic testing, and preventing repeated counts. Use Problem → Test → Fix → Learning.
14. **Benefits and Limitations:** Educational value, contactless sensing, automatic movement, serial feedback; also explain one-sensor limitations and fixed timer.
15. **Future Scope:** LCD/OLED, separate exit sensor, ESP32 dashboard, occupancy alert, better crossing detection, and obstruction safety.
16. **Conclusion:** Summarise Detect, Process, Count, Control, Learn. End with “Thank You” and questions.

Make diagrams technically accurate, keep explanations easy to present aloud, and preserve the same dark technology theme across all slides. Do not add an IR sensor to the current hardware and do not claim that the prototype is ready to control a full-size gate.
