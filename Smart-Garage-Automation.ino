#include <Servo.h>

/*
  SMART GARAGE AUTOMATION & VEHICLE COUNTER
  Board: Arduino Uno
  Sensor: HC-SR04 ultrasonic sensor
  Actuator: SG90 positional servo

  Behaviour:
  - Counts a new detection when an object is at or within 15 cm.
  - Opens the miniature gate to the commanded 90-degree position.
  - Commands the gate closed after 3 seconds.
  - Rearms the counter after the sensor reports a clear area for 700 ms.

  Note: The sensor detects objects, not cars specifically. This is an
  educational prototype, not a safety-rated controller for a full-size gate.
*/

#include <Servo.h>

Servo gateServo;

// Hardware pins
const byte TRIG_PIN  = 7;
const byte ECHO_PIN  = 8;
const byte SERVO_PIN = 9;

// Settings
const int DETECTION_DISTANCE_CM = 15;
const int CLEAR_DISTANCE_CM = 20;  // Hysteresis helps reduce count flicker
const int GATE_CLOSED_DEG = 0;
const int GATE_OPEN_DEG = 90;

const unsigned long GATE_OPEN_DURATION_MS = 3000;
const unsigned long CLEAR_CONFIRMATION_MS = 700;
const unsigned long ECHO_TIMEOUT_US = 30000;

// State
unsigned long totalCars = 0;
unsigned long gateOpenedAt = 0;
unsigned long clearStartedAt = 0;

bool currentObjectCounted = false;
bool clearTimerRunning = false;
bool gateIsOpen = false;

long getDistanceCm() {
  // Send a clean 10-microsecond trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for the echo pulse. A timeout means no valid echo was received.
  const unsigned long duration = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);

  if (duration == 0) {
    return -1;
  }

  // Speed of sound is approximately 0.0343 cm per microsecond.
  // Divide by two because the sound travels to the object and back.
  return (long)(duration * 0.0343 / 2.0);
}

void printVehicleEvent() {
  Serial.println();
  Serial.println(F("================================"));
  Serial.print(F("🚗 CAR PASSED #"));
  Serial.println(totalCars);
  Serial.println(F("📡 Status: Object detected"));
  Serial.print(F("🔢 Total detection events: "));
  Serial.println(totalCars);
  Serial.println(F("================================"));
}

void openGate() {
  gateServo.write(GATE_OPEN_DEG);
  gateIsOpen = true;
  gateOpenedAt = millis();
  Serial.println(F("🚧 GATE STATUS: OPEN"));
}

void closeGate() {
  gateServo.write(GATE_CLOSED_DEG);
  gateIsOpen = false;
  Serial.println(F("🚧 GATE STATUS: CLOSED"));
  Serial.println(F("✅ Ready for the next detection"));
  Serial.println();
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);

  gateServo.attach(SERVO_PIN);
  gateServo.write(GATE_CLOSED_DEG);

  Serial.println();
  Serial.println(F("================================"));
  Serial.println(F("   SMART GARAGE SYSTEM"));
  Serial.println(F("================================"));
  Serial.println(F("✅ System Status: ONLINE"));
  Serial.println(F("🚧 Gate Status: CLOSED"));
  Serial.println(F("🔢 Car Counter: READY"));
  Serial.println(F("📡 Ultrasonic Sensor: ACTIVE"));
  Serial.println(F("================================"));
  Serial.println(F("Waiting for a detection event..."));
  Serial.println();
}

void loop() {
  const unsigned long now = millis();
  const long distanceCm = getDistanceCm();

  const bool inDetectionZone =
      (distanceCm > 0 && distanceCm <= DETECTION_DISTANCE_CM);

  const bool areaLooksClear =
      (distanceCm < 0 || distanceCm >= CLEAR_DISTANCE_CM);

  // Count once when an object first enters the detection zone.
  if (inDetectionZone) {
    clearTimerRunning = false;

    if (!currentObjectCounted) {
      currentObjectCounted = true;
      totalCars++;

      printVehicleEvent();
      openGate();
    }
  }
  // Rearm only after the area appears clear for a short, continuous period.
  // This helps reduce duplicate counts caused by small distance fluctuations.
  else if (currentObjectCounted) {
    if (areaLooksClear) {
      if (!clearTimerRunning) {
        clearTimerRunning = true;
        clearStartedAt = now;
      } else if (now - clearStartedAt >= CLEAR_CONFIRMATION_MS) {
        currentObjectCounted = false;
        clearTimerRunning = false;
        Serial.println(F("📡 Detection zone clear; counter re-armed."));
      }
    } else {
      // In the 16–19 cm buffer zone, do not treat the object as fully gone.
      clearTimerRunning = false;
    }
  }

  // Close the gate after the configured interval.
  if (gateIsOpen && now - gateOpenedAt >= GATE_OPEN_DURATION_MS) {
    closeGate();
  }

  delay(50);
}
