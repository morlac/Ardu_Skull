uint8_t v0, v1, v2;

void fade_left_eye_center_left(uint8_t d) {}
void fade_right_eye_center_left(uint8_t d) {}
void fade_eyes_center_left(uint8_t d) {
  #ifdef DEBUG
  Serial.println("fade_eyes_center_left");
  #endif

  for (uint8_t v=0; v<=100; v++){
    v0 = outer_max1 + v * (center_max - outer_max1) / 100;
    v1 = center_max + v * (outer_max1 - center_max) / 100;
    v2 = outer_max1 + v * (outer_max2 - outer_max1) / 100;
    
    set_left_eye(left_eye_color, v0, v1, v2);
    set_right_eye(right_eye_color, v0, v1, v2);

    delay(d);
  }
}

void fade_left_eye_left_center(uint8_t d) {}
void fade_right_eye_left_center(uint8_t d) {}
void fade_eyes_left_center(uint8_t d) {
  #ifdef DEBUG
  Serial.println("fade_eyes_left_center");
  #endif

  for (uint8_t v=0; v<=100; v++){
    v0 = center_max + v * (outer_max1 - center_max) / 100;
    v1 = outer_max1 + v * (center_max - outer_max1) / 100;
    v2 = outer_max2 + v * (outer_max1 - outer_max2) / 100;
    
    set_left_eye(left_eye_color, v0, v1, v2);
    set_right_eye(right_eye_color, v0, v1, v2);

    delay(d);
  }
}

void fade_left_eye_center_right(uint8_t d) {}
void fade_right_eye_center_right(uint8_t d) {}
void fade_eyes_center_right(uint8_t d) {
  #ifdef DEBUG
  Serial.println("fade_eyes_center_right");
  #endif

  for (uint8_t v=0; v<=100; v++){
    v0 = outer_max1 + v * (outer_max2 - outer_max1) / 100;
    v1 = center_max + v * (outer_max1 - center_max) / 100;
    v2 = outer_max1 + v * (center_max - outer_max1) / 100;

    set_left_eye(left_eye_color, v0, v1, v2);
    set_right_eye(right_eye_color, v0, v1, v2);

    delay(d);
  }
}

void fade_left_eye_right_center(uint8_t d) {}
void fade_right_eye_right_center(uint8_t d) {}
void fade_eyes_right_center(uint8_t d) {
  #ifdef DEBUG
  Serial.println("fade_eyes_right_center");
  #endif

  for (uint8_t v=0; v<=100; v++){
    v0 = outer_max2 + v * (outer_max1 - outer_max2) / 100;
    v1 = outer_max1 + v * (center_max - outer_max1) / 100;
    v2 = center_max + v * (outer_max1 - center_max) / 100;
    
    set_left_eye(left_eye_color, v0, v1, v2);
    set_right_eye(right_eye_color, v0, v1, v2);

    delay(d);
  }
}

