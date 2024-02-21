

// ** This is the code from the individual down below 
// that allows me to work with the accelerometer easily. **

// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include "Wire.h" // This library allows you to communicate with I2C devices.
const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.
int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
//int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data
char tmp_str[7]; // temporary variable used in convert function
char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

/*
 * 
 */
/*
 * Variables for the boxes outputs
 */
 /* Known phrases */
 
String phrases[] = {"Ask me again    later bitch", "You know what?I think so. ", "Meh. Maybe.", "Actually- Yes", "As I see it,  you're a fool, lol", "Most likely", "With what     you've been    through, sure", "Yes", "My reply is   Don't be so   full of       yourself", "Very doubtful", "No", "Not a chance", "No way", "Probably not  bruh", "I doubt it", "Ask again", "Who knows,    ask me later."};
String output;
int numberofphrases = 17; //Number of phrases known, must be the same as, well, the number of phrases known

/*
 * These variables are for the Nokia LCD
 */
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

boolean backlight = true;
int contrast=40;


/*
 * These are the variables for the menu that was mostly written by the youtube channel educ8s.tv
 * 
 * I'm modifying to remove the contrast option and 
 * to use the menus for the different programs to be done.
 */

volatile boolean up = false;
volatile boolean down = false;
volatile boolean middle = false;

int downButtonState = 0;
int upButtonState = 0;  
int selectButtonState = 0;          
int lastDownButtonState = 0;
int lastSelectButtonState = 0;
int lastUpButtonState = 0;

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
 
void setup() 
{
  
  //Pins for the buttons
  pinMode(2, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  randomSeed(analogRead(5)); //Seed for random number generation
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  /*
   * This is for the Nokia 5110 LCD display
   * The pinout is 
   */
  display.begin();
  display.setContrast(25);
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
  
}
void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  
  
  //drawMenu();

  
  readData();
  //displayText(); 
  
  shakeMe(); 
  //printData();
  
  display.display();
  // delay
  delay(500);

  
  
}
