#define DEBUG
#define RANDOM_PIN A7
#define HSV_Gold 36
#define HSV_Orange 21
#define HSV_Blue 128
#define HSV_Red 0

#include "FastSPI_LED2.h"

#define NUM_LEDS 6
#define DATA_PIN 13

CRGB leds[NUM_LEDS];

uint8_t left_eye_color = HSV_Gold;
uint8_t right_eye_color = HSV_Gold;

const uint8_t center_max = 196;
const uint8_t outer_max1 = 52;
const uint8_t outer_max2 = 16;

void setup(void) {
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("--------------------\n\trunning setup");
#endif

  delay(2000);
  LEDS.addLeds<WS2811_400, DATA_PIN>(leds, NUM_LEDS);

  open_eyes_centered(0);
}

uint32_t get_delay(uint32_t base, uint32_t range) {
  uint32_t r = analogRead(RANDOM_PIN);
  return base + (range * r / 1024);
}


uint32_t d = 0;
uint32_t previousMillis = 0;

void loop() {

  if (millis() - previousMillis > d) {
    previousMillis = millis(); 

    blink_eyes_centered();
    delay(2000);
    //  close_eyes_centered(0);
    //  delay(500);
    //  open_eyes_left(0);
    //  delay(1000);
    //  blink_eyes_left();
    //  delay(1000);
    //  close_eyes_left(0);
    //  delay(1000);
    //  open_eyes_centered(0);
    //  delay(1000);
    //  close_eyes_centered(0);
    //  delay(1000);
    //  open_eyes_right(0);
    //  delay(1000);
    //  blink_eyes_right();
    //  delay(1000);
    //  close_eyes_right(0);
    //  delay(1000);
    //  open_eyes_centered(0);
    delay(2000);
    fade_eyes_center_left(100);
    delay(2000);
    blink_eyes_left();
    delay(2000);
    fade_eyes_left_center(20);
    delay(2000);
    blink_eyes_centered();
    delay(2000);  
    fade_eyes_center_right(20);
    delay(2000);
    blink_eyes_right();
    delay(2000);
    fade_eyes_right_center(100);

    delay(2000);

    close_eyes_centered(0);

    delay(10000);

    flash_eyes_centered(5, 250, 5);

    delay(10000);

    flash_eyes_left(5, 2500, 5);

    delay(10000);

    flash_eyes_right(5, 2500, 5);

    d = get_delay(15000, 10000);

#ifdef DEBUG
    Serial.print("loop waiting ");
    Serial.print(d);
    Serial.println(" milliseconds.");
#endif
  }
}

