# Smart Garage Automation and Vehicle Counter — Project Report

## 1. Aim

To build an educational miniature garage system that detects nearby objects with an ultrasonic sensor, increments a running detection counter, and moves a gate using a servo motor.

## 2. Components and Their Roles

### Arduino Uno
The microcontroller that runs the program, reads the ultrasonic sensor, maintains the count, controls the servo, and sends messages to the Serial Monitor.

### HC-SR04 Ultrasonic Sensor
A non-contact distance sensor. It transmits an ultrasonic burst and measures the time taken for the echo to return. Arduino converts the time into an approximate distance.

### SG90 Micro Servo
A small positional actuator. The program commands the servo to 0° for the closed position and 90° for the open position. The physical orientation depends on how the servo horn and gate are mounted.

### USB Cable, Jumper Wires, and Gate Structure
The USB cable is used for programming and serial communication; jumper wires provide circuit connections; lightweight cardboard or sticks can be used to construct the miniature gate.

## 3. Pin Connections

| Device | Signal / wire | Arduino |
|---|---|---|
| HC-SR04 | TRIG | D7 |
| HC-SR04 | ECHO | D8 |
| HC-SR04 | VCC | 5V |
| HC-SR04 | GND | GND |
| SG90 | Signal (orange) | D9 |
| SG90 | Power (red) | 5V supply |
| SG90 | Ground (brown) | GND |

## 4. Working Principle

1. Arduino sends a 10-microsecond trigger pulse to the HC-SR04.
2. The sensor returns an echo pulse whose duration is used to estimate distance.
3. A valid reading at or below 15 cm is treated as a new detection if the current object has not already been counted.
4. The running counter increases and a message is printed to the Serial Monitor.
5. The servo is commanded to 90°.
6. After 3 seconds, the servo is commanded to 0°.
7. The counter re-arms only after the sensor indicates a clear zone for 700 ms. The program uses a 20 cm clear threshold to reduce repeated counts from small changes in distance.

## 5. Why These Components Were Chosen

- **Arduino Uno:** approachable, programmable, and widely used in educational prototyping.
- **HC-SR04:** low-cost way to demonstrate non-contact distance measurement.
- **SG90:** compact and convenient for moving a lightweight miniature gate.
- **Serial Monitor:** provides immediate feedback during testing and debugging.

## 6. Benefits

- Demonstrates the integration of sensing, decision logic, and actuation.
- Provides immediate feedback about detection events.
- Encourages learning in electronics, programming, and debugging.
- Uses components suitable for a tabletop educational prototype.

## 7. Development Challenges and Lessons

### Upload/COM-Port Error
The IDE reported that access to COM6 was denied. The debugging procedure included closing serial tools, reconnecting the board, checking the selected port, and ensuring that another application was not using it. The lesson is that compilation and uploading are separate stages.

### Servo Position Testing
A small standalone servo sketch was used to command 0° and test movement toward 90°. The lesson is to verify individual components before integrating them.

### Ultrasonic Sensor Testing
A standalone sketch printed distance values to the Serial Monitor. The lesson is to isolate sensor testing when debugging a larger program.

### Repeated Detection Events
Because Arduino repeatedly checks the sensor, one object may generate many readings. A state flag and clear-zone confirmation timer help avoid counting the same continuous detection repeatedly.

## 8. Limitations

- The sensor detects objects, not vehicle identity.
- A single sensor cannot reliably determine whether an object entered or exited.
- The program counts detection events, not guaranteed unique vehicles or current occupancy.
- The count resets after power loss or an Arduino restart.
- The gate uses a fixed time and does not verify that the path is clear before closing.
- This is a miniature learning prototype, not a safety-certified real-gate controller.

## 9. Future Scope

- Add a separate exit sensor and direction-aware detection logic.
- Use a two-sensor sequence to validate complete crossings.
- Add an LCD/OLED counter display.
- Add ESP32 connectivity and a dashboard.
- Store counts or events persistently.
- Add occupancy limits, obstruction detection, and a safety mechanism.

## 10. Conclusion

The prototype demonstrates how an Arduino Uno, an HC-SR04 ultrasonic sensor, and an SG90 servo can work together. It provides hands-on experience with distance measurement, state tracking, servo control, serial monitoring, and systematic debugging. More sensors, validation logic, and safety measures would be needed for real-world deployment.
