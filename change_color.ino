/*
 *
 */
void change_color_center(uint8_t src_h, uint8_t dst_h, uint32_t d) {
  #ifdef DEBUG
  Serial.print("change_color_center: ");
  Serial.print(src_h);
  Serial.print(" => ");
  Serial.println(dst_h);
  #endif
  
  for (uint8_t h = src_h; h != dst_h; h += (src_h < dst_h) ? 1 : -1) {
    left_eye_color = right_eye_color = h;
    
    set_left_eye_centered(left_eye_color, 100);
    set_right_eye_centered(right_eye_color, 100);

    FastLED.show();
    FastLED.delay(d);
  }
}

/*
 *
 */
void change_color_left(uint8_t src_h, uint8_t dst_h, uint32_t d) {
  #ifdef DEBUG
  Serial.print("change_color_left: ");
  Serial.print(src_h);
  Serial.print(" => ");
  Serial.println(dst_h);
  #endif

  for (uint8_t h = src_h; h != dst_h; h += (src_h < dst_h) ? 1 : -1) {
    left_eye_color = right_eye_color = h;
    
    set_left_eye_left(left_eye_color, 100);
    set_right_eye_left(right_eye_color, 100);

    FastLED.show();
    FastLED.delay(d);
  }
}

/*
 *
 */
void change_color_right(uint8_t src_h, uint8_t dst_h, uint32_t d) {
  #ifdef DEBUG
  Serial.print("change_color_right: ");
  Serial.print(src_h);
  Serial.print(" => ");
  Serial.println(dst_h);
  #endif

  for (uint8_t h = src_h; h != dst_h; h += (src_h < dst_h) ? 1 : -1) {
    left_eye_color = right_eye_color = h;
    
    set_left_eye_right(left_eye_color, 100);
    set_right_eye_right(right_eye_color, 100);

    FastLED.show();
    FastLED.delay(d);
  }
}
