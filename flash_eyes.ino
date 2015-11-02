

/*
 *
 */
void flash_eyes_center(uint8_t count, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4) {
  #ifdef DEBUG 
  Serial.println("flash_eyes centered");
  #endif

  uint32_t stay_open, stay_closed;

  for (uint8_t c = 0; c < count; c++) {
    open_eyes_centered(d1);

    stay_open = get_delay(d2/2, d2/2);
    FastLED.delay(stay_open);

    close_eyes_centered(d3);

    stay_closed = get_delay(d4/2, d4/2);
    FastLED.delay(stay_closed);
  }
}

/*
 *
 */
void flash_eyes_left(uint8_t count, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4) {
  #ifdef DEBUG
  Serial.println("flash_eyes_left");
  #endif

  uint8_t stay_open, stay_closed;

  for (uint8_t c = 0; c < count; c++) {
    open_eyes_left(d1);

    stay_open = get_delay(d2/2, d2/2);
    FastLED.delay(stay_open);

    close_eyes_left(d3);

    stay_closed = get_delay(d4/2, d4/2);
    FastLED.delay(stay_closed);
  }
}

/*
 *
 */
void flash_eyes_right(uint8_t count, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4) {
  #ifdef DEBUG
  Serial.println("flash_eyes_right");
  #endif

  uint32_t stay_open, stay_closed;

  for (uint8_t c = 0; c < count; c++) {
    open_eyes_right(d1);

    stay_open = get_delay(d2/2, d2/2);
    FastLED.delay(stay_open);

    close_eyes_right(d3);

    stay_closed = get_delay(d4/2, d4/2);
    FastLED.delay(stay_closed);
  }
}

