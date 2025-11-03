// book_map.h
#ifndef BOOK_MAP_H
#define BOOK_MAP_H

struct BookEntry {
  const char* uid;
  uint16_t track;
};

// Predefined RFID tag UIDs mapped to MP3 file tracks
BookEntry bookMap[] = {
  {"04A3D2C1", 1}, // "Operating Systems"
  {"03B4E1F9", 2}, // "Data Structures"
  {"12345678", 3}  // Example
};

const int BOOK_MAP_SIZE = sizeof(bookMap)/sizeof(bookMap[0]);

#endif
