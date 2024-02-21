/*
 * This is a dual axis joystick skitch for Arduino.
 * The position of joystick is read and displayed on serial monitor
 */
 
 /*
  * Libraries used  *  
  */ 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define sw 6
#define screenWidth 600
#define screenHeight 300

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  
  pinMode(sw,INPUT_PULLUP);// setting pin sw as input
  pinMode(13,OUTPUT);
}
 
void loop() {
  // Robojax Dual Axis joystick project
  int x = analogRead(A0);// read analog
  int y = analogRead(A1);
  int xPos = map(x, 0, 1023,0,screenWidth);
  int yPos = map(y, 0, 1023,0,screenHeight); 
  int sStat = digitalRead(sw);//
  // Robojax project
  Serial.print("X: ");
  Serial.print(xPos);

  Serial.print(" Y: ");
  Serial.println(yPos);// Robojax prints y
  if(sStat ==LOW){
    Serial.println("Switch pressed");
    display.clearDisplay();
    digitalWrite(13,HIGH);// Turn LED ON
  }else{
    digitalWrite(13,LOW);// Turn LED OFF
  }
  delay(500);

  // text display tests for lcd

  
  display.setCursor(0,0);
  delay(2000);
  display.clearDisplay();


  
}
