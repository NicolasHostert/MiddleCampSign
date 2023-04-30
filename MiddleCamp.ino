#include <Adafruit_NeoPixel.h>

// DEFINE AND VAR ALL THE THINGS
#define TESTPIN            6 // datapin for the strip
#define TESTNUMPIXELS      13 // Number of LEDs
#define SLIDERDELAY  50 // Delay in sliderfull and sliderblock modes 
#define TESTDELAY 150   // Delay for the init script
Adafruit_NeoPixel teststrip = Adafruit_NeoPixel(TESTNUMPIXELS, TESTPIN, NEO_GRB + NEO_KHZ800);

void loop() {
  // Running sequence. 
  // sliderfull(0,0,255); // RGB 
  // sliderblock(0,0,255,3); // RGB, size of block
  // breathing(0,0,255,15); // RGB, delay
  // sliderfullbounce(0,0,255); // RGB 
  sliderblockbounce(0,255,255,3); // RGB , size of block
}

void setup() {
  // To confirm the strip is working as planned. Goes Off, Red, Green, Blue, Off (+2s pause).
  teststrip.begin();
  blackout();
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 255, 0, 0);    //turn every pixel off
  }
  teststrip.show();
  delay(TESTDELAY);
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 0, 255, 0);    //turn every pixel off
  }
  teststrip.show();
  delay(TESTDELAY);
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 0, 0, 255);    //turn every pixel off
  }
  teststrip.show();
  delay(TESTDELAY);
  blackout();
  delay(2000);
}

void sliderfull(int color1, int color2, int color3) {
  // Fills the strip and drains it afterwards, always same direction
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), color1, color2, color3);
    teststrip.show();
    delay(SLIDERDELAY);
  }
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), 0, 0, 0);
    teststrip.show();
    delay(SLIDERDELAY);
  }
}

void sliderfullbounce(int color1, int color2, int color3) {
  // Fills the strip and drains it afterwards, opposite direction
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), color1, color2, color3);
    teststrip.show();
    delay(SLIDERDELAY);
  }
  for (int i = 100; i > 1; i = i - 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), 0, 0, 0);
    teststrip.show();
    delay(SLIDERDELAY);
  }
}

void sliderblock(int color1, int color2, int color3, int blocksize) {
  // Slides a block of LEDs across
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), color1, color2, color3);
    teststrip.setPixelColor(((i*teststrip.numPixels()/100)-blocksize), 0, 0, 0);
    teststrip.show();
    delay(SLIDERDELAY);
  }
}

void sliderblockbounce(int color1, int color2, int color3, int blocksize) {
  // Bounces a block of LEDs across
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), color1, color2, color3);
    teststrip.setPixelColor(((i*teststrip.numPixels()/100)-blocksize), 0, 0, 0);
    teststrip.show();
    delay(SLIDERDELAY);
  }
  for (int i = 99; i > 0; i = i - 1) {
    teststrip.setPixelColor((i*teststrip.numPixels()/100), 0, 0, 0);
    teststrip.setPixelColor(((i*teststrip.numPixels()/100)-blocksize), color1, color2, color3);
    teststrip.show();
    delay(SLIDERDELAY);
  }
}

void blackout() {
  // Turns the strip all back
  for (int i = 0; i < teststrip.numPixels(); i = i + 1) {
    teststrip.setPixelColor(i, 0, 0, 0);    //turn every pixel off
  }
  teststrip.show();

}

void breathing(int color1, int color2, int color3, int delayvalue) {
  // Goes from 0 to 255 power on the specified colors, back to 0
  for (int level = 0; level < 255; level = level + 5) {
    for (int i = 0; i < 99; i = i + 1) {
      teststrip.setPixelColor((i*teststrip.numPixels()/100), (level*color1/255) , (level*color2/255), (level*color3/255));
    }
    teststrip.show();
    delay(delayvalue);
  }
   for (int level = 255; level > 0; level = level - 5) {
    for (int i = 0; i < 99; i = i + 1) {
      teststrip.setPixelColor((i*teststrip.numPixels()/100), (level*color1/255) , (level*color2/255), (level*color3/255));
      }
    teststrip.show();
    delay(delayvalue);
  }
}


