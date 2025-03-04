#include <FastLED.h>

#define LED_PIN     4
#define NUM_LEDS    14
#define LIGHT_THRESHOLD 400
CRGB leds[NUM_LEDS];

int pirPin = 5;
const int lightPin = A0;
int pirState = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
  delay(7500);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop()
{
  int lightState = analogRead(lightPin);
  Serial.print("Light value: ");
  Serial.println(lightState);
  pirState = digitalRead(pirPin);  
  if (lightState < LIGHT_THRESHOLD) {
    if (pirState == HIGH) {
      seePerson();
    } else {
      dimLevel(lightState);
    }
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
}

void dimLevel(int brightness) {
  int level = map(brightness, 0, LIGHT_THRESHOLD, 0, 255);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(level/3, level*2/3, level);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB(level/3, level*2/3, level);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void seePerson() {
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(5000);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}
