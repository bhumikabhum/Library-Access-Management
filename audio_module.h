// audio_module.h
#ifndef AUDIO_MODULE_H
#define AUDIO_MODULE_H

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#define DF_RX 6
#define DF_TX 5

SoftwareSerial dfSerial(DF_RX, DF_TX);
DFRobotDFPlayerMini player;

void initAudio() {
  dfSerial.begin(9600);
  if (!player.begin(dfSerial)) {
    Serial.println(F("DFPlayer not found!"));
    while (true);
  }
  player.volume(20); // Volume: 0–30
}

void playTrack(uint16_t track) {
  player.play(track);
}

#endif
