
/*
 *
 */
void blink_center(uint8_t count, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4) {
  #ifdef DEBUG
  Serial.println("blink center");
  #endif

  uint32_t stay_opened, stay_closed;

  for (uint8_t c = 0; c < count; c++) {
    close_eyes_centered(d1);

    stay_closed = get_delay(d2/2, d2/2);
    FastLED.delay(stay_closed);

    open_eyes_centered(d3);

    stay_opened = get_delay(d4/2, d4/2);
    FastLED.delay(stay_opened);
  }
}

/*
 *
 */
void blink_left(uint8_t count, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4) {
  #ifdef DEBUG
  Serial.println("blink right");
  #endif

  uint32_t stay_opened, stay_closed;

  for (uint8_t c = 0; c < count; c++) {
    close_eyes_left(d1);

    stay_closed = get_delay(d2/2, d2/2);
    FastLED.delay(stay_closed);

    open_eyes_left(d3);

    stay_opened = get_delay(d4/2, d4/2);
    FastLED.delay(stay_opened);
  }
}

/*
 *
 */
void blink_right(uint8_t count, uint32_t d1, uint32_t d2, uint32_t d3, uint32_t d4) {
  #ifdef DEBUG
  Serial.println("blink right");
  #endif

  uint32_t stay_opened, stay_closed;

  for (uint8_t c = 0; c < count; c++) {
    close_eyes_right(d1);

    stay_closed = get_delay(d2/2, d2/2);
    FastLED.delay(stay_closed);

    open_eyes_right(d3);

    stay_opened = get_delay(d4/2, d4/2);
    FastLED.delay(stay_opened);
  }
}

