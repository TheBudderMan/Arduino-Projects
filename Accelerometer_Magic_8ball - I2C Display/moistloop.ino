/*
 * this should be the animated loop for the moist lady when you shake the box
 */



void moistAnimation()
{
  display.clearDisplay();
  display.drawBitmap(0, 0,  moist, 84, 64, 1);
  display.display();
  delay(250);
  
  display.clearDisplay();
  display.drawBitmap(0, 0,  moist2, 84, 64, 1);
  
  display.display();
  delay(150);

  display.clearDisplay();
  display.drawBitmap(0, 0,  moist3, 84, 64, 1); 
  display.display();
  delay(150);
  
  display.clearDisplay();  
  display.drawBitmap(0, 0,  moist4, 84, 64, 1);  
  display.display();
  delay(150);
  
  display.clearDisplay();  
  display.drawBitmap(0, 0,  moist5, 84, 64, 1); 
  display.display();
  delay(150);

  display.clearDisplay();  
  display.drawBitmap(0, 0,  moist6, 84, 64, 1); 
  display.display();
  delay(150);

  display.clearDisplay();  
  display.drawBitmap(0, 0,  moist, 84, 64, 1); 
  display.display();
  delay(150);
  
  

} 

void moistEnd()
{
  display.clearDisplay();  
  display.drawBitmap(0, 0,  whysomoist, 84, 64, 1); 
  display.display();
  delay(1500);
  display.clearDisplay();
  
}
