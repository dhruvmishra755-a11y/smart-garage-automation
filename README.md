<div align="center">
  <img src="assets/hero-banner.svg" alt="Smart Garage Automation and Vehicle Counter" width="100%" />
  <br />
  <img src="https://img.shields.io/badge/Platform-Arduino%20Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino Uno" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Project-STEM%20%7C%20IoT-blueviolet?style=for-the-badge" alt="STEM IoT project" />
  <br /><br />
  <h1>🚗 Smart Garage Automation & Vehicle Counter</h1>
  <p><strong>Detect it. Count it. Open the gate.</strong></p>
  <p>A beginner-friendly Arduino project that uses an ultrasonic sensor to detect nearby objects, counts detection events, and controls a miniature gate with an SG90 servo motor.</p>
</div>

---

## ✨ Overview

This project demonstrates how a sensor, a microcontroller, and a motor can work together to create a simple automated garage prototype.

When an object comes within **15 cm** of the HC-SR04 ultrasonic sensor, the Arduino records a new detection event, commands the SG90 servo to move the gate to **90°**, and returns the gate to its commanded **0°** position after **3 seconds**. Event details appear in the Arduino Serial Monitor.

> **Important:** The HC-SR04 detects objects, not cars specifically. This prototype counts detection events that simulate vehicles; it does not guarantee that every event represents a unique car or a complete vehicle crossing.

## 🎯 Features

- 📡 Non-contact distance measurement with an HC-SR04.
- 🔢 Running detection-event counter.
- 🚧 Automatic miniature gate movement using an SG90 servo.
- ✅ Serial Monitor status messages at 9600 baud.
- 🧠 Detection-state tracking to avoid counting the same continuous detection repeatedly.
- 🛠️ Clear, beginner-friendly code with comments.

## 🧰 Components

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno | 1 | Reads the sensor and controls the system |
| HC-SR04 ultrasonic sensor | 1 | Measures distance to a nearby object |
| SG90 micro servo | 1 | Moves the miniature gate |
| USB cable | 1 | Uploads the program and connects to Serial Monitor |
| Jumper wires | As needed | Connects the circuit |
| Cardboard / ice-cream sticks | As needed | Builds the miniature gate structure |
| Breadboard | Optional | Makes temporary connections easier |

## 🔌 Wiring

### HC-SR04 → Arduino Uno

| HC-SR04 pin | Arduino Uno pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D7 |
| ECHO | D8 |

### SG90 servo → Arduino Uno

| Servo wire | Connection |
|---|---|
| Orange (signal) | D9 |
| Red (power) | 5V supply |
| Brown (ground) | GND |

![Smart Garage wiring diagram](assets/wiring-diagram.svg)

**Power note:** A servo can draw current in short bursts. If the Arduino resets, the servo jitters, or sensor readings become unreliable, use a suitable regulated 5V supply for the servo and connect the supply ground to Arduino GND. Do not power a larger gate mechanism with an SG90.

## ⚙️ How It Works

1. **Start:** Arduino configures the ultrasonic sensor and sets the gate to its closed command (0°).
2. **Measure:** The HC-SR04 sends an ultrasonic pulse and reports the echo duration.
3. **Calculate:** Arduino estimates distance using `distance = duration × 0.0343 / 2` (in centimetres when duration is in microseconds).
4. **Detect:** A valid distance of **15 cm or less** triggers a new event if the current object has not already been counted.
5. **Count:** `totalCars` increases by one and the Serial Monitor prints the event.
6. **Open:** The servo is commanded to 90°.
7. **Close:** After 3 seconds, the servo is commanded back to 0°.
8. **Re-arm:** The counter becomes ready for another event after the sensor indicates a clear area for 700 ms. A 20 cm clear threshold helps reduce repeated counts caused by small distance fluctuations.

## 🖥️ Example Serial Monitor Output

Set **Tools → Serial Monitor → 9600 baud** after uploading the sketch.

```text
================================
   SMART GARAGE SYSTEM
================================
✅ System Status: ONLINE
🚧 Gate Status: CLOSED
🔢 Car Counter: READY
📡 Ultrasonic Sensor: ACTIVE
================================
Waiting for a detection event...

================================
🚗 CAR PASSED #1
📡 Status: Object detected
🔢 Total detection events: 1
================================
🚧 GATE STATUS: OPEN
🚧 GATE STATUS: CLOSED
✅ Ready for the next detection
```

*Output shown is an illustrative example. Emoji rendering depends on the serial monitor's font and encoding; the text labels are the important information.*

## 🚀 Getting Started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect the HC-SR04 and SG90 using the wiring tables above.
3. Open `Smart-Garage-Automation/Smart-Garage-Automation.ino` in Arduino IDE.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct port under **Tools → Port**.
6. Click **Upload**.
7. Open **Tools → Serial Monitor** and choose **9600 baud**.
8. Move a target into the sensor's detection zone and observe the counter and gate movement.

The sketch uses Arduino's built-in `Servo` library. No additional third-party library is required.

## 🧪 Testing Checklist

- [ ] The Arduino uploads the sketch successfully.
- [ ] The Serial Monitor shows `SMART GARAGE SYSTEM` at 9600 baud.
- [ ] The sensor detects an object within 15 cm.
- [ ] One continuous detection produces one count.
- [ ] The servo moves toward 90° after detection.
- [ ] The gate returns toward 0° after 3 seconds.
- [ ] Moving the object away allows the sensor logic to re-arm.

## 🛠️ Troubleshooting

| Problem | Checks |
|---|---|
| Upload says `Access is denied` | Close Serial Monitor/Serial Plotter, reconnect USB, select the port that appears, and close other apps using it. |
| No Serial Monitor output | Confirm the correct port and set baud rate to 9600. |
| Distance never changes | Check TRIG → D7, ECHO → D8, VCC → 5V, GND → GND, and test with a flat object in front of the sensor. |
| Servo does not move | Check signal → D9, power polarity, common GND, and whether the supply can provide enough current. |
| Servo jitters or Arduino resets | Try a separate regulated 5V servo supply; connect its GND to Arduino GND. |
| Counts the same object again | Ensure the object leaves the detection zone long enough for the clear-state timer to finish. Review sensor placement and reflections. |
| Emoji looks like boxes or strange symbols | Use the text labels, or replace emoji strings in the sketch with plain ASCII text. |

## 📚 What I Learned

- Connecting sensors and actuators to a microcontroller.
- Measuring distance with ultrasonic echo timing.
- Using Boolean variables to track a detection state.
- Controlling servo position and timing.
- Printing status events through serial communication.
- Debugging upload, wiring, and component-testing problems one step at a time.

## 🔭 Future Improvements

- Add a small LCD/OLED to show the count without a computer.
- Add a separate exit sensor to estimate current garage occupancy.
- Use sensor sequencing to detect a complete crossing more reliably.
- Add an ESP32 and a web dashboard for remote monitoring.
- Add occupancy limits and alerts.
- Add obstruction detection and safety logic before considering larger mechanisms.
- Store events or counts persistently if required.

These are proposed improvements, not features implemented in the current sketch.

## ⚠️ Limitations and Safety

- One ultrasonic sensor cannot determine direction of travel or distinguish a car from another object.
- The counter tracks detection events; it is not a verified count of unique cars inside a garage.
- The count is stored in RAM and resets when the Arduino restarts or loses power.
- The gate closes after a fixed 3-second interval; the program does not verify that an object has cleared the gate.
- This is an educational miniature prototype, not a safety-rated controller for a real garage gate.
- Keep fingers clear of the moving linkage and use only a lightweight gate arm with the SG90.

## 📁 Repository Structure

```text
Smart-Garage-Automation/
├── README.md
├── .gitignore
├── assets/
│   ├── hero-banner.svg
│   └── wiring-diagram.svg
├── docs/
│   ├── PROJECT-REPORT.md
│   └── PRESENTATION-OUTLINE.md
└── Smart-Garage-Automation/
    └── Smart-Garage-Automation.ino
```

## 🙌 Credits

Built as a learning project to explore Arduino, distance sensing, servo control, and basic automation.

**Project tagline:** *Detect it. Count it. Open the gate.*
