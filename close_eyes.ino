

/*
 *
 */
void close_eyes_left(uint8_t d) {
  #ifdef DEBUG
  Serial.println("close_eyes_left");
  #endif

  set_left_eye_left(left_eye_color, 100);
  set_right_eye_left(right_eye_color, 100);

  if (d == 0) {
    FastLED.setBrightness(0);
    FastLED.show();
  } else {
    for (uint8_t b=255; b>=1; b--) {
      FastLED.setBrightness(b);
      FastLED.show();
      FastLED.delay(d);
    }
  }
}

/*
 *
 */
void close_eyes_right(uint8_t d) {
  #ifdef DEBUG
  Serial.println("close_eyes_right");
  #endif

  set_left_eye_right(left_eye_color, 100);
  set_right_eye_right(right_eye_color, 100);

  if (d == 0) {
    FastLED.setBrightness(0);
    FastLED.show();
  } else {
    for (uint8_t b=255; b>=1; b--) {
      FastLED.setBrightness(b);
      FastLED.show();
      FastLED.delay(d);
    }
  }
}

/*
 *
 */
void close_eyes_centered(uint8_t d) {
  #ifdef DEBUG
  Serial.println("close_eyes_centered");
  #endif

  set_left_eye_centered(left_eye_color, 100);
  set_right_eye_centered(right_eye_color, 100);

  if (d == 0) {
    FastLED.setBrightness(0);
    FastLED.show();
  } else {
    for (uint8_t b=255; b>=1; b--) {
      LEDS.setBrightness(b);
      LEDS.show();
      FastLED.delay(d);
    }
  }
}

