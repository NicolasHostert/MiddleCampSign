#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define TESTPIN            6

// How many NeoPixels are attached to the Arduino?
#define TESTNUMPIXELS      15

Adafruit_NeoPixel teststrip = Adafruit_NeoPixel(TESTNUMPIXELS, TESTPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  teststrip.begin();
  // black
  blackout();
  // red
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 255, 0, 0);    //turn every pixel off
  }
  teststrip.show();
  delay(150);
  // green
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 0, 255, 0);    //turn every pixel off
  }
  teststrip.show();
  delay(150);
  // blue
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 0, 0, 255);    //turn every pixel off
  }
  teststrip.show();
  delay(150);
  // black
  blackout();
  delay(2000);
}

void sliderfull(int color1, int color2, int color3) {
  int pause = 50;
  // Off first
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), color1, color2, color3);
    teststrip.show();
    delay(pause);
  }
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), 0, 0, 0);
    teststrip.show();
    delay(pause);
  }
}

void sliderblock(int color1, int color2, int color3) {
  int pause = 50;
  int blocksize = 4;

  // Off first
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), color1, color2, color3);
    teststrip.setPixelColor(((i*teststrip.numPixels()/100)-blocksize), 0, 0, 0);
    teststrip.show();
    delay(pause);
  }
}

void blackout() {
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 0, 0, 0);    //turn every pixel off
  }
  teststrip.show();

}

void loop() {
  // put your main code here, to run repeatedly:
  sliderblock(0,0,255);
}
