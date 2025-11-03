// ultrasonic_module.h
#ifndef ULTRASONIC_MODULE_H
#define ULTRASONIC_MODULE_H

#define TRIG_PIN 7
#define ECHO_PIN 8

void initUltrasonic() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

long getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 20000);
  if (duration == 0) return -1;
  long distance = duration * 0.034 / 2;
  return distance;
}

#endif
