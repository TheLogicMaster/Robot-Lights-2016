#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN    6
#define PIXEL_COUNT 7
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
int increment = 0;

int pattern = 0;
int cycleNum0 = 0;
int cycleNum1 = 0;
int cycleNum2 = 0;
int cycleNum3 = 0;
int cycleNum4 = 0;
int cycleNum5 = 0;
int cycleNum6 = 0;

int increment0 = 1;
int increment1 = 1;
int increment2 = 1;
int increment3 = 1;
int increment4 = 1;
int increment5 = 1;
int increment6 = 1;

void setup() {
Serial.begin(9600);
strip.begin();
strip.show();
cycleNum0 = rand() % 25;
cycleNum1 = rand() % 25;
cycleNum2 = rand() % 25;
cycleNum3 = rand() % 25;
cycleNum4 = rand() % 25;
cycleNum5 = rand() % 25;
cycleNum6 = rand() % 25;
}

void loop() {
switch(pattern){
case 0: pattern0(90, 68 , 3); //Color range, start color, speed
break;
case 1: pattern1(1);
}
strip.show();
}
void pattern0(int colorMax, int color, int speeed){
Serial.println(increment0);
increment++;
if (increment >= speeed){
strip.setPixelColor(0, Wheel((color + cycleNum0) % 255));
strip.setPixelColor(1, Wheel((color + cycleNum1) % 255));
strip.setPixelColor(2, Wheel((color + cycleNum2) % 255));
strip.setPixelColor(3, Wheel((color + cycleNum3) % 255));
strip.setPixelColor(4, Wheel((color + cycleNum4) % 255));
strip.setPixelColor(5, Wheel((color + cycleNum5) % 255));
strip.setPixelColor(6, Wheel((color + cycleNum6) % 255));

cycleNum0 = cycleNum0 + increment0;
cycleNum1 = cycleNum1 + increment1;
cycleNum2 = cycleNum2 + increment2;
cycleNum3 = cycleNum3 + increment3;
cycleNum4 = cycleNum4 + increment4;
cycleNum5 = cycleNum5 + increment5;
cycleNum6 = cycleNum6 + increment6;

if (cycleNum0 + color >= colorMax || cycleNum0 +color <= color){
increment0 = increment0 * -1;
}
if (cycleNum1 + color >= colorMax || cycleNum1 + color <= color){
increment1 = increment1 * -1;
}
if (cycleNum2 + color >= colorMax || cycleNum2 + color <= color){
increment2 = increment2 * -1;
}
if (cycleNum3 + color >= colorMax || cycleNum3 + color <= color){
increment3 = increment3 * -1;
}
if (cycleNum4 + color >= colorMax || cycleNum4 + color <= color){
increment4 = increment4 * -1;
}
if (cycleNum5 +color >= colorMax || cycleNum5 + color <= color){
increment5 = increment5 * -1;
}
if (cycleNum6 + color >= colorMax || cycleNum6 + color <= color){
increment6 = increment6 * -1;
}
increment = 0;
}
}
void pattern1(int value){

}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

