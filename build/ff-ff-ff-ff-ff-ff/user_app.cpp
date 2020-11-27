#include <Arduino.h>
#include <vector>
#include <WiFi.h>
#include <Wire.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

#include "KB_initBoard.h"
#include "KB_music.h"
#include "KB_LDR.h"
#include "KB_LM73.h"
#include "KB_ht16k33.h"
#include "MCP7941x.h"
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
MCP7941x rtc = MCP7941x();

KB_board board = KB_board();
KB_music music = KB_music();
KB_LDR ldr = KB_LDR();
KB_LM73 lm73 = KB_LM73();
KB_8x16Matrix matrix = KB_8x16Matrix();

typedef int Number;
typedef int Boolean;
using namespace std;

void setup() {
  board.begin();
  music.begin();
  lm73.begin();
  matrix.displayBegin();
  ldr.begin();

  Serial.begin(115200);
}
void loop() {
  Serial.println(String("print"));
  Serial.println();

  Wire.beginTransmission(0x70);delayMicroseconds(1);Wire.write(0x01);Wire.write(0x01);Wire.endTransmission();delay(100);
  tft.init();tft.setRotation(1);tft.invertDisplay(1);tft.fillScreen(TFT_BLACK);delay(100);
  Wire.beginTransmission(0x70);delayMicroseconds(1);Wire.write(0xEF);Wire.endTransmission();delay(30);

  tft.fillScreen(0xc800);
  delay(3000);
}