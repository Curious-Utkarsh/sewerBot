void servoBracket()
{
  //For Servo Bracket
  xValL = analogRead(xPinL);
  yValL = analogRead(yPinL);
  sValL = digitalRead(sPinL);
//  Serial.println(xValL);
//  Serial.println(yValL);
//  Serial.println();;

  if(xValL <= 10)
  {
    servoPan.write(posPan);         
    delay(dtServo);   
    if(posPan > 0)
    {
      posPan = posPan - 1;
    }              
  }
  
  if(xValL >= 900)
  {
    servoPan.write(posPan);         
    delay(dtServo);   
    if(posPan < 180)
    {
      posPan = posPan + 1; 
    } 
  }

  if(yValL <= 10)
  {
    servoTilt.write(posTilt);         
    delay(dtServo);   
    if(posTilt > 0)
    {
      posTilt = posTilt - 1; 
    }                  
  }
  
  if(yValL >= 900)
  {
    servoTilt.write(posTilt);         
    delay(dtServo);   
    if(posTilt < 180)
    {
      posTilt = posTilt + 1; 
    } 
  }

  if(sValL == 0)
  {
    posPan = 100;
    posTilt = 150;
    servoPan.write(posPan);
    servoTilt.write(posTilt);
  }
}
