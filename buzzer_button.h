// buzzer_button.h
#ifndef BUZZER_BUTTON_H
#define BUZZER_BUTTON_H

#define BUTTON_PIN 2
#define BUZZER_PIN 3

void initButtonBuzzer() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

bool buttonPressed() {
  return digitalRead(BUTTON_PIN) == LOW;
}

void beep(int ms) {
  tone(BUZZER_PIN, 2000);
  delay(ms);
  noTone(BUZZER_PIN);
}

#endif
