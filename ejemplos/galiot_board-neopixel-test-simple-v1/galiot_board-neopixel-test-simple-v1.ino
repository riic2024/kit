//GALIoT Board - LED RGB - Parte 1

// Software based on:
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 14 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50);
  Serial.begin(115200);
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  delay (1000);
  Serial.println("Iniciando");

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color (color verde):
    pixels.setPixelColor(i, pixels.Color(90, 0, 90));
    pixels.show();   // Send the updated pixel colors to the hardware.
    Serial.println("Ciclo 1");
    delay(DELAYVAL); // Pause before next pass through loop
  }

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright red color (color rojo):
    pixels.setPixelColor(i, pixels.Color(0, 90, 90));
    pixels.show();   // Send the updated pixel colors to the hardware.
    Serial.println("Ciclo 2");
    delay(DELAYVAL); // Pause before next pass through loop
  }

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright blue color (color azul):
    pixels.setPixelColor(i, pixels.Color(90, 90, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    Serial.println("Ciclo 3");
    delay(DELAYVAL); // Pause before next pass through loop
  }

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright blue color (color azul):
    pixels.setPixelColor(i, pixels.Color(45, 45, 45));
    pixels.show();   // Send the updated pixel colors to the hardware.
    Serial.println("Ciclo 4");
    delay(DELAYVAL); // Pause before next pass through loop
  }
}
