
/*
 *
 */
void set_left_eye(uint8_t h, uint8_t v0, uint8_t v1, uint8_t v2) {
//  #ifdef DEBUG
//  Serial.print("set_left_eye:");
//  Serial.print(" v0: "); Serial.print(v0);
//  Serial.print(" v1: "); Serial.print(v1);
//  Serial.print(" v2: "); Serial.print(v2);
//  Serial.println();
//  #endif

  leds[0].setHSV(h, 255, v0);
  leds[1].setHSV(h, 255, v1);
  leds[2].setHSV(h, 255, v2);
}

/*
 *
 */
void set_right_eye(uint8_t h, uint8_t v0, uint8_t v1, uint8_t v2) {
//  #ifdef DEBUG
//  Serial.print("set_right_eye:");
//  Serial.print(" v0: "); Serial.print(v0);
//  Serial.print(" v1: "); Serial.print(v1);
//  Serial.print(" v2: "); Serial.print(v2);
//  Serial.println();
//  #endif

  leds[3].setHSV(h, 255, v0);
  leds[4].setHSV(h, 255, v1);
  leds[5].setHSV(h, 255, v2);
}

/*
 *
 */
void set_left_eye_centered(uint8_t h, uint8_t v) {
  uint8_t vo = outer_max1 * v / 100;
  set_left_eye(h, vo, center_max * v / 100, vo);
}

/*
 *
 */
void set_right_eye_centered(uint8_t h, uint8_t v) {
  uint8_t vo = outer_max1 * v / 100;
  set_right_eye(h, vo, center_max * v / 100, vo);
}

/*
 *
 */
void set_left_eye_left(uint8_t h, uint8_t v) {
  set_left_eye(h, center_max * v / 100, outer_max1 * v / 100, outer_max2 * v / 100);
}

/*
 *
 */
void set_right_eye_left(uint8_t h, uint8_t v) {
  set_right_eye(h, center_max * v / 100, outer_max1 * v / 100, outer_max2 * v / 100);
}

/*
 *
 */
void set_left_eye_right(uint8_t h, uint8_t v) {
  set_left_eye(h, outer_max2 * v / 100, outer_max1 * v / 100, center_max * v / 100);
}

/*
 *
 */
void set_right_eye_right(uint8_t h, uint8_t v) {
  set_right_eye(h, outer_max2 * v / 100, outer_max1 * v / 100, center_max * v / 100);
}

