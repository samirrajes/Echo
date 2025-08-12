#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#define SERVOMIN 150
#define SERVOMAX 600
#define DIRECT_SERVO_PIN 9
const uint8_t NUM_SERVOS = 49;
const uint16_t UPDATE_PERIOD = 100;

Adafruit_PWMServoDriver pwm[3] = {
  Adafruit_PWMServoDriver(0x40),
  Adafruit_PWMServoDriver(0x41),
  Adafruit_PWMServoDriver(0x42)
};
Servo directServo;

uint8_t  latest[NUM_SERVOS];
bool     haveNew = false;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) { /* wait */ }
  Wire.begin();
  for (uint8_t b = 0; b < 3; b++) {
    pwm[b].begin();
    pwm[b].setPWMFreq(50);
  }
  directServo.attach(DIRECT_SERVO_PIN);
}

void loop() {
  // drain every complete 49-byte frame, keep only last one
  while (Serial.available() >= NUM_SERVOS) {
    Serial.readBytes(latest, NUM_SERVOS);
    haveNew = true;
  }

  // update only the servos once every UPDATE_PERIOD
  unsigned long now = millis();
  if (haveNew && (now - lastUpdate) >= UPDATE_PERIOD) {
    lastUpdate = now;
    haveNew = false;

    // swap mis‐wired channels in buffer:
    // we swap some of the servo addresses due to wires not being long enough in our physical setup
    // servo 3 w/ servo 15
    uint8_t tmp = latest[2];
    latest[2]   = latest[14];
    latest[14]  = tmp;
    // servo 35 w/ servo 44
    tmp         = latest[34];
    latest[34]  = latest[43];
    latest[43]  = tmp;

    // echo back for debug
    Serial.write(latest, NUM_SERVOS);

    // apply to 48 PCA9685 channels + 1 direct servo
    for (uint8_t i = 0; i < NUM_SERVOS; i++) {
      int bitVal = latest[i];
      int angle  = bitVal ? -5 : 45;
      int pulse  = map(angle, 0, 180, SERVOMIN, SERVOMAX);

      if (i < 48) {
        uint8_t b = i / 16, ch = i % 16;
        pwm[b].setPWM(ch, 0, pulse);
      } else {
        directServo.write(angle);
      }
    }
  }

  delay(1);
}
