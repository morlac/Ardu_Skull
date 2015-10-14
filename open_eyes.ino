void open_eyes_left(uint8_t d) {
  #ifdef DEBUG
  Serial.println("open_eyes_left");
  #endif

  for (uint8_t v=1; v<=100; v++) {
    set_left_eye_left(left_eye_color, v);
    set_right_eye_left(right_eye_color, v);
    delay(d);
  }
}

void open_eyes_right(uint8_t d) {
  #ifdef DEBUG
  Serial.println("open_eyes_right");
  #endif

  for (uint8_t v=1; v<=100; v++) {
    set_left_eye_right(left_eye_color, v);
    set_right_eye_right(right_eye_color, v);
    delay(d);
  }
}

void open_eyes_centered(uint8_t d) {
  #ifdef DEBUG
  Serial.println("open_eyes_centered");
  #endif

  for (uint8_t v=1; v<=100; v++) {
    set_left_eye_centered(left_eye_color, v);
    set_right_eye_centered(right_eye_color, v);
    delay(d);
  }
}

