//#define DEBUG

#define RANDOM_PIN A7

#define HSV_Gold 36
#define HSV_Orange 21
#define HSV_Blue 128
#define HSV_Green 95
#define HSV_Yellow 42
#define HSV_Red 0

#include "FastLED.h"

#define NUM_LEDS 6
//#define DATA_PIN 13
#define DATA_PIN 5

CRGB leds[NUM_LEDS];
uint8_t colors[] = {HSV_Gold, HSV_Orange, HSV_Yellow, HSV_Red, HSV_Blue, HSV_Blue, HSV_Green, HSV_Green};

uint8_t left_eye_color;
uint8_t right_eye_color;

const uint8_t center_max = 196;
const uint8_t outer_max1 = 52;
const uint8_t outer_max2 = 16;

enum eye_states{closed, open_center, open_left, open_right};
enum eye_states eye_state;

/*
 *
 */
void setup(void) {
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("--------------------\n\trunning setup");
#endif

  delay(2000);
//  LEDS.addLeds<WS2811_400, DATA_PIN>(leds, NUM_LEDS);
  LEDS.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);

  randomSeed(analogRead(RANDOM_PIN));
  left_eye_color = right_eye_color =
    colors[random(sizeof(colors))];

  #ifdef DEBUG
  Serial.print("Chosen color: ");
  Serial.println(left_eye_color);
  #endif

  open_eyes_centered(10);

  uint8_t
    temp_color1 = left_eye_color,
    temp_color2 = left_eye_color;
    
  while (temp_color1 == temp_color2) {
    temp_color2 = colors[random(sizeof(colors))];
  }

  change_color_center(temp_color1, temp_color2, 10);
  
  FastLED.delay(2500);
  
  change_color_center(temp_color2, temp_color1, 10);

  blink_center(2, 10, 1500, 10, 2000);
  
  blink_center(2, 0, 1500, 0, 2000);

  fade_eyes_center_left(10);
  blink_left(2, 10, 1500, 10, 2000);
  
  blink_left(2, 0, 1500, 0, 2000);
  
  fade_eyes_left_center(10);
  blink_center(2, 10, 1500, 10, 2000);
  
  blink_center(2, 0, 1500, 0, 2000);
  
  fade_eyes_center_right(10);
  blink_right(2, 10, 1500, 10, 2000);
  
  blink_right(2, 0, 1500, 0, 2000);
  
  fade_eyes_right_center(10);

  close_eyes_centered(10);
  
  flash_eyes_center(2, 1, 1500, 1, 2000);
  
  flash_eyes_left(2, 1, 1500, 1, 2000);

  flash_eyes_right(2, 1, 1500, 1, 2000);
  
  eye_state = closed;
  #ifdef DEBUG
  Serial.println("setup done ..\n");
  #endif
}

/*
 *
 */
uint32_t get_delay(uint32_t base, uint32_t range) {
  uint32_t r = analogRead(RANDOM_PIN);
  return base + (range * r / 1024);
}


uint32_t d = 0;
uint32_t previousMillis = 0;

/*
 *
 */
void loop() {
  #ifdef DEBUG
  Serial.println("entering loop\n");
  #endif

  if (millis() - previousMillis > d) {
    previousMillis = millis(); 

    randomSeed(analogRead(RANDOM_PIN));
    uint8_t effect = random(4); // effect_count
    uint8_t eye_direction, eye_speed, flash_count, new_color;

    switch (effect) {
      case 0: // open or close eyes
        eye_speed = get_delay(0, 12);

        switch (eye_state) {
          case closed:
            randomSeed(analogRead(RANDOM_PIN));
            eye_direction = random(3);

            switch (eye_direction) {
              case 0:
                open_eyes_centered(eye_speed);
                eye_state = open_center;
                break;
              case 1:
                open_eyes_left(eye_speed);
                eye_state = open_left;
                break;
              case 2:
                open_eyes_right(eye_speed);
                eye_state = open_right;
                break;
            }

            break;
          case open_left:
            close_eyes_left(eye_speed);
            eye_state = closed;
            break;
          case open_center:
            close_eyes_centered(eye_speed);
            eye_state = closed;
            break;
          case open_right:
            close_eyes_right(eye_speed);
            eye_state = closed;
            break;
        }
        break;
      case 1: // fade ..
        randomSeed(analogRead(RANDOM_PIN));
        eye_direction = random(2);
        eye_speed = get_delay(0, 12);

        switch (eye_state) {
          case closed:
            break;
          case open_left:

            switch (eye_direction) {
              case 0: // center
                fade_eyes_left_center(eye_speed);
                eye_state = open_center;
                break;
              case 1: // center + right
                fade_eyes_left_center(eye_speed);
                fade_eyes_center_right(eye_speed);
                eye_state = open_right;
                break;
            }
            break;
          case open_center:
            switch (eye_direction) {
              case 0:
                fade_eyes_center_left(eye_speed);
                eye_state = open_left;
                break;
              case 1:
                fade_eyes_center_right(eye_speed);
                eye_state = open_right;
                break;
            }
            break;
          case open_right:
            randomSeed(analogRead(RANDOM_PIN));
            eye_direction = random(2);

            switch (eye_direction) {
              case 0: // center
                fade_eyes_right_center(eye_speed);
                eye_state = open_center;
                break;
              case 1: // center + left
                fade_eyes_right_center(eye_speed);
                fade_eyes_center_left(eye_speed);
                eye_state = open_left;
                break;
            }
            break;
        }
        break;
      case 2: // blink or flash
        switch (eye_state) {
          case closed: // flash
            randomSeed(analogRead(RANDOM_PIN));
            eye_direction = random(3);
            eye_speed = get_delay(0, 12);
            flash_count = random(1, 10);
            
            switch (eye_direction) {
              case 0:
                flash_eyes_left(flash_count, get_delay(0, 12), random(5000), get_delay(0, 12), random(30000));
                break;
              case 1:
                flash_eyes_center(flash_count, get_delay(0, 12), random(5000), get_delay(0, 12), random(30000));
                break;
              case 2:
                flash_eyes_right(flash_count, get_delay(0, 12), random(5000), get_delay(0, 12), random(30000));
                break;
            }
            
            break;
          case open_left: // blink_left
            blink_left(flash_count, get_delay(0, 12), random(5000), get_delay(0, 12), random(30000));
            break;
          case open_center:
            blink_center(flash_count, get_delay(0, 12), random(5000), get_delay(0, 12), random(30000));
            break;
          case open_right:
            blink_right(flash_count, get_delay(0, 12), random(5000), get_delay(0, 12), random(30000));
            break;
        }
        break;
      case 3:
        randomSeed(analogRead(RANDOM_PIN));
        new_color =
          colors[random(sizeof(colors))];
    
        switch (eye_state) {
          case closed:
            left_eye_color = right_eye_color = new_color;
            break;
          case open_left:
            change_color_left(left_eye_color, new_color, get_delay(0, 20));
            break;
          case open_center:
            change_color_center(left_eye_color, new_color, get_delay(0, 20));
            break;
          case open_right:
            change_color_right(left_eye_color, new_color, get_delay(0, 20));
            break;
        }
        break;
    }

    d = get_delay(15000, 10000);

#ifdef DEBUG
    Serial.print("loop waiting ");
    Serial.print(d);
    Serial.println(" milliseconds.");
#endif

    FastLED.delay(d);

  }
}

