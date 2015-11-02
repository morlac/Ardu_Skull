

/*
 *
 */
void open_eyes_left(uint8_t d) {
  #ifdef DEBUG
  Serial.println("open_eyes_left");
  #endif

  set_left_eye_left(left_eye_color, 100);
  set_right_eye_left(right_eye_color, 100);

  if (d == 0) {
    FastLED.setBrightness(255);
    FastLED.show();
  } else {
    for (uint8_t b=0; b < 255; b++) {
      FastLED.setBrightness(b);
      FastLED.show();
      FastLED.delay(d);
    }
  }
}

/*
 *
 */
void open_eyes_right(uint8_t d) {
  #ifdef DEBUG
  Serial.println("open_eyes_right");
  #endif

  set_left_eye_right(left_eye_color, 100);
  set_right_eye_right(right_eye_color, 100);

  if (d == 0) {
    FastLED.setBrightness(255);
    FastLED.show();
  } else {
    for (uint8_t b=0; b < 255; b++) {
      FastLED.setBrightness(b);
      FastLED.show();
      FastLED.delay(d);
    }
  }
}

/*
 *
 */
void open_eyes_centered(uint8_t d) {
  #ifdef DEBUG
  Serial.println("open_eyes_centered");
  #endif

  set_left_eye_centered(left_eye_color, 100);
  set_right_eye_centered(right_eye_color, 100);

  if (d == 0) {
    FastLED.setBrightness(255);
    FastLED.show();
  } else {
    for (uint8_t b=0; b < 255; b++) {
      FastLED.setBrightness(b);
      FastLED.show();
      FastLED.delay(d);
    }
  }
}

