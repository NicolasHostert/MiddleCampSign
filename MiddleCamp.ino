// DEFINE AND VAR ALL THE THINGS
#include <Adafruit_NeoPixel.h>
#define SLIDERDELAY  50 // Delay in sliderfull and sliderblock modes 
#define TESTDELAY 150   // Delay for the init script

// teststrip definition
#define TESTPIN            6 // datapin for the strip
#define TESTNUMPIXELS      13 // Number of LEDs
Adafruit_NeoPixel teststrip = Adafruit_NeoPixel(TESTNUMPIXELS, TESTPIN, NEO_GRB + NEO_KHZ800);

// rabbit definition
#define RABBITPIN            6 // datapin for the strip
#define RABBITNUMPIXELS      100 // Number of LEDs
Adafruit_NeoPixel rabbitstrip = Adafruit_NeoPixel(RABBITNUMPIXELS, RABBITPIN, NEO_GRB + NEO_KHZ800);

// ring1 definition
#define RING1PIN            7 // datapin for the strip
#define RING1NUMPIXELS      13 // Number of LEDs
Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(RING1NUMPIXELS, RING1PIN, NEO_GRB + NEO_KHZ800);

// ring2 definition
#define RING2PIN            8 // datapin for the strip
#define RING2NUMPIXELS      13 // Number of LEDs
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(RING2NUMPIXELS, RING2PIN, NEO_GRB + NEO_KHZ800);

// ring3 definition
#define RING3PIN            9 // datapin for the strip
#define RING3NUMPIXELS      13 // Number of LEDs
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(RING3NUMPIXELS, RING3PIN, NEO_GRB + NEO_KHZ800);

// ring4 definition
#define RING4PIN            10 // datapin for the strip
#define RING4NUMPIXELS      13 // Number of LEDs
Adafruit_NeoPixel ring4 = Adafruit_NeoPixel(RING4NUMPIXELS, RING4PIN, NEO_GRB + NEO_KHZ800);

// ring5 definition
#define RING5PIN            11 // datapin for the strip
#define RING5NUMPIXELS      13 // Number of LEDs
Adafruit_NeoPixel ring5 = Adafruit_NeoPixel(RING5NUMPIXELS, RING5PIN, NEO_GRB + NEO_KHZ800);

// TO DO: sliderblock / sliderblockbounce / breathing

void loop() {
  // Running sequence. 
  sliderfull(0,0,255); // RGB 
  // sliderblock(0,0,255,3); // RGB, size of block
  // breathing(0,0,255,15); // RGB, delay
  // sliderfullbounce(0,0,255); // RGB 
  // sliderblockbounce(150,0,255,3); // RGB , size of block
}

void setup() {
  // To confirm the strip is working as planned. Goes Off, Red, Green, Blue, Off (+2s pause).
  rabbitstrip.begin();
  ring1.begin();
  ring2.begin();
  ring3.begin();
  ring4.begin();
  ring5.begin();
  blackout();
  for (int i = 0; i < rabbitstrip.numPixels(); i = i + 1) {
    rabbitstrip.setPixelColor(i, 255, 0, 0);    //turn every pixel red
  }
  rabbitstrip.show();
  delay(TESTDELAY);
  for (int i = 0; i < rabbitstrip.numPixels(); i = i + 1) {
    rabbitstrip.setPixelColor(i, 0, 255, 0);    //turn every pixel green
  }
  rabbitstrip.show();
  delay(TESTDELAY);
  for (int i = 0; i < rabbitstrip.numPixels(); i = i + 1) {
    rabbitstrip.setPixelColor(i, 0, 0, 255);    //turn every pixel blue
  }
  rabbitstrip.show();
  delay(TESTDELAY);
  blackout();
  delay(2000);
}

void blackout() {
  // Turns the strips all back
  for (int i = 0; i < rabbitstrip.numPixels(); i = i + 1) {
    rabbitstrip.setPixelColor(i, 0, 0, 0);
  }
  for (int i = 0; i < ring1.numPixels(); i = i + 1) {
    ring1.setPixelColor(i, 0, 0, 0);
  }
  for (int i = 0; i < ring2.numPixels(); i = i + 1) {
    ring2.setPixelColor(i, 0, 0, 0);
  }
  for (int i = 0; i < ring3.numPixels(); i = i + 1) {
    ring3.setPixelColor(i, 0, 0, 0);
  }
  for (int i = 0; i < ring4.numPixels(); i = i + 1) {
    ring4.setPixelColor(i, 0, 0, 0);
  }
  for (int i = 0; i < ring5.numPixels(); i = i + 1) {
    ring5.setPixelColor(i, 0, 0, 0);
  }
  rabbitstrip.show();
  ring1.show();
  ring2.show();
  ring3.show();
  ring4.show();
  ring5.show();
}

void rabbit(int color1, int color2, int color3) {
  // Turns the strips all back
  for (int i = 0; i < rabbitstrip.numPixels(); i = i + 1) {
    rabbitstrip.setPixelColor(i, color1, color2, color3);
  }
}

void sliderfull(int color1, int color2, int color3) {
  // Fills the strip and drains it afterwards, always same direction
  blackout();
  rabbit(204,0,204); // Purple rabbit
  for (int i = 0; i < 99; i = i + 1) {
    ring1.setPixelColor((i*ring1.numPixels()/100), color1, color2, color3);
    ring2.setPixelColor((i*ring2.numPixels()/100), color1, color2, color3);
    ring3.setPixelColor((i*ring3.numPixels()/100), color1, color2, color3);
    ring4.setPixelColor((i*ring4.numPixels()/100), color1, color2, color3);
    ring5.setPixelColor((i*ring5.numPixels()/100), color1, color2, color3);
    ring1.show();
    ring2.show();
    ring3.show();
    ring4.show();
    ring5.show();
    delay(SLIDERDELAY);
  }
  for (int i = 0; i < 99; i = i + 1) {
    ring1.setPixelColor((i*ring1.numPixels()/100), 0, 0, 0);
    ring2.setPixelColor((i*ring2.numPixels()/100), 0, 0, 0);
    ring3.setPixelColor((i*ring3.numPixels()/100), 0, 0, 0);
    ring4.setPixelColor((i*ring4.numPixels()/100), 0, 0, 0);
    ring5.setPixelColor((i*ring5.numPixels()/100), 0, 0, 0);
    ring1.show();
    ring2.show();
    ring3.show();
    ring4.show();
    ring5.show();
    delay(SLIDERDELAY);
  }
}

void sliderfullbounce(int color1, int color2, int color3) {
  // Fills the strip and drains it afterwards, opposite direction
  blackout();
  for (int i = 0; i < 99; i = i + 1) {
    ring1.setPixelColor((i*ring1.numPixels()/100), color1, color2, color3);
    ring2.setPixelColor((i*ring2.numPixels()/100), color1, color2, color3);
    ring3.setPixelColor((i*ring3.numPixels()/100), color1, color2, color3);
    ring4.setPixelColor((i*ring4.numPixels()/100), color1, color2, color3);
    ring5.setPixelColor((i*ring5.numPixels()/100), color1, color2, color3);
    ring1.show();
    ring2.show();
    ring3.show();
    ring4.show();
    ring5.show();
    delay(SLIDERDELAY);
  }
  for (int i = 100; i > 1; i = i - 1) {
    ring1.setPixelColor((i*ring1.numPixels()/100), 0, 0, 0);
    ring2.setPixelColor((i*ring2.numPixels()/100), 0, 0, 0);
    ring3.setPixelColor((i*ring3.numPixels()/100), 0, 0, 0);
    ring4.setPixelColor((i*ring4.numPixels()/100), 0, 0, 0);
    ring5.setPixelColor((i*ring5.numPixels()/100), 0, 0, 0);
    ring1.show();
    ring2.show();
    ring3.show();
    ring4.show();
    ring5.show();
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


