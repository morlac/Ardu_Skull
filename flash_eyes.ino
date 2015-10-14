void flash_eyes_centered(uint32_t d1, uint32_t d2, uint32_t d3) {
  #ifdef DEBUG 
  Serial.println("flash_eyes");
  #endif

  open_eyes_centered(d1);

  delay(d2);

  close_eyes_centered(d3);
}

void flash_eyes_left(uint32_t d1, uint32_t d2, uint32_t d3) {
  #ifdef DEBUG
  Serial.println("flash_eyes_left");
  #endif

  open_eyes_left(d1);

  delay(d2);

  close_eyes_left(d3);
}

void flash_eyes_right(uint32_t d1, uint32_t d2, uint32_t d3) {
  #ifdef DEBUG
  Serial.println("flash_eyes_right");
  #endif

  open_eyes_right(d1);

  delay(d2);

  close_eyes_right(d3);
}

