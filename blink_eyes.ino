void blink_eyes_centered() {
  #ifdef DEBUG 
  Serial.println("blink_eyes");
  #endif

  close_eyes_centered(0);

  uint32_t d = get_delay(250, 500);

//  #ifdef DEBUG
//  Serial.print("waiting ");
//  Serial.print(d);
//  Serial.println(" milliseconds.");
//  #endif

  delay(d);

  open_eyes_centered(0);
}

void blink_eyes_left() {
  #ifdef DEBUG
  Serial.println("blink_eyes_left");
  #endif

  close_eyes_left(0);

  uint32_t d = get_delay(250, 500);

//  #ifdef DEBUG
//  Serial.print("waiting ");
//  Serial.print(d);
//  Serial.println(" milliseconds.");
//  #endif

  delay(d);

  open_eyes_left(0);
}

void blink_eyes_right() {
  #ifdef DEBUG
  Serial.println("blink_eyes_right");
  #endif

  close_eyes_right(0);

  uint32_t d = get_delay(250, 500);

//  #ifdef DEBUG
//  Serial.print("waiting ");
//  Serial.print(d);
//  Serial.println(" milliseconds.");
//  #endif

  delay(d);

  open_eyes_right(0);
}

