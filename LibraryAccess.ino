#include "rfid_module.h"
#include "ultrasonic_module.h"
#include "audio_module.h"
#include "buzzer_button.h"

const int NEAR_DISTANCE = 40;
unsigned long lastPress = 0;

void setup() {
  Serial.begin(115200);
  initRFID();
  initUltrasonic();
  initAudio();
  initButtonBuzzer();

  Serial.println(F("Library Access System Ready"));
  playTrack(10); // "System ready" audio
}

void loop() {
  if (buttonPressed()) {
    if (millis() - lastPress < 500) return; // debounce
    lastPress = millis();

    Serial.println(F("Button pressed → Starting search"));
    playTrack(10); // "Start search"
    delay(1000);

    long dist = getDistanceCM();
    if (dist > 0 && dist < NEAR_DISTANCE) {
      Serial.println(F("Near shelf detected"));
      playTrack(11); // "Near shelf"
      beep(200);
      delay(500);

      String uid = readRFIDTag();
      if (uid != "") {
        Serial.print(F("Detected UID: "));
        Serial.println(uid);

        int track = getBookTrack(uid);
        if (track > 0) {
          playTrack(track); // play corresponding book audio
        } else {
          playTrack(12); // "Book not registered"
        }
      } else {
        playTrack(14); // "No book detected"
      }
    } else {
      playTrack(13); // "Move closer to shelf"
    }
  }
}
