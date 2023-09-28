void servoBracket()
{
  if(xVal <= 10)
  {
    servoPan.write(posPan);         
    delay(dt);   
    if(posPan > 0)
    {
      posPan = posPan - 1;
    }              
  }
  
  if(xVal >= 1013)
  {
    servoPan.write(posPan);         
    delay(dt);   
    if(posPan < 180)
    {
      posPan = posPan + 1; 
    } 
  }

  if(yVal <= 10)
  {
    servoTilt.write(posTilt);         
    delay(dt);   
    if(posTilt > 0)
    {
      posTilt = posTilt - 1; 
    }                  
  }
  
  if(yVal >= 1013)
  {
    servoTilt.write(posTilt);         
    delay(dt);   
    if(posTilt < 180)
    {
      posTilt = posTilt + 1; 
    } 
  }

  if(sVal == 0)
  {
    posPan = 90;
    posTilt = 150;
    servoPan.write(posPan);
    servoTilt.write(posTilt);
  }
}
