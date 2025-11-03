// rfid_module.h
#ifndef RFID_MODULE_H
#define RFID_MODULE_H

#include <MFRC522.h>
#include <SPI.h>
#include "book_map.h"

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void initRFID() {
  SPI.begin();
  mfrc522.PCD_Init();
}

String readRFIDTag() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return "";
  }
  String uidStr = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uidStr += "0";
    uidStr += String(mfrc522.uid.uidByte[i], HEX);
  }
  uidStr.toUpperCase();
  mfrc522.PICC_HaltA();
  return uidStr;
}

int getBookTrack(String uid) {
  for (int i = 0; i < BOOK_MAP_SIZE; i++) {
    if (uid == String(bookMap[i].uid)) return bookMap[i].track;
  }
  return -1;
}

#endif
