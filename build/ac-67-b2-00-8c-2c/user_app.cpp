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

float p = 3.1415926;

void setup() {
  board.begin();
  music.begin();
  lm73.begin();
  matrix.displayBegin();
  ldr.begin();

  Serial.begin(115200);
  Serial.print("Hello! ST7735 TFT Test");
  Serial.println("HT16K33 test");

  uint16_t time = millis();
  tft.fillScreen(TFT_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  Serial.println("done");
  delay(1000);
}

void loop() {
  Serial.println("Initialized LCD");
  Wire.beginTransmission(0x70);  // transmit to device #4
  delayMicroseconds(1);
  Wire.write(0x01);        // sends one byte
  Wire.write(0x01);        // sends one byte
  Wire.endTransmission();  // stop transmitting
  delay(100);

  // Use this initializer if you're using a 0.96" TFT
  tft.init();  // initialize a ST7735S chip
  tft.setRotation(1);
  tft.invertDisplay(1);
  tft.fillScreen(TFT_BLACK);
  delay(100);

  Wire.beginTransmission(0x70);  // transmit to device #4
  delayMicroseconds(1);
  Wire.write(0xEF);        // sends one byte
  Wire.endTransmission();  // stop transmitting
  delay(30);

  Serial.println("Initialized");
  tft.fillScreen(TFT_BLACK);
  delay(1000);
  tft.fillScreen(TFT_RED);
  delay(1000);
  tft.fillScreen(TFT_GREEN);
  delay(1000);
  tft.fillScreen(TFT_BLUE);
  delay(1000);
  // large block of text
  tft.fillScreen(TFT_BLACK);

  tft.setTextWrap(false);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(TFT_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(TFT_BLUE);
  tft.setTextSize(4);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(TFT_GREEN);
  tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX);  // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(TFT_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(TFT_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(TFT_WHITE);
  tft.print(" seconds.");

  delay(3000);

  Serial.println("Initialized LED");
  Wire.beginTransmission(0x70);  // transmit to device #4
  delayMicroseconds(1);
  Wire.write(0x01);        // sends one byte
  Wire.write(0x00);        // sends one byte
  Wire.endTransmission();  // stop transmitting
  delay(500);
  //
  matrix.printText(0, 0, " ");
  matrix.scrollText(String(String("Change to mode Kidbright32")));
  delay(1000);
}