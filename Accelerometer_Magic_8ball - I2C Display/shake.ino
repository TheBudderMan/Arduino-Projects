void shakeMe()
{
  int aXConv = accelerometer_x / 64;
  
  
  int x = analogRead(0); //Reading of z axis
  if (aXConv > 100 || aXConv < -100) //Limits- change if you want to, depending on how hard you shake things
  {
 
    display.clearDisplay();
    moistAnimation();
    moistAnimation();
    moistEnd();
    delay(500);
    output = phrases[random(numberofphrases)]; //Chooses phrase
    display.setCursor(0, 3);
    display.print("Daddy says....");
    display.setCursor(0, 15);
    
    display.print(output); //Displays it
  }
  delay(400); //Waits for a bit
}



