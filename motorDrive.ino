void motorDrive()
{
  //For Motor Drive
  xValR = analogRead(xPinR);
  yValR = analogRead(yPinR);

//  Serial.println(xValR);
//  Serial.println(yValR);
//  Serial.println();

  if(xValR <= 485)
  {
    digitalWrite(dirPin1,HIGH);   //Forward
    digitalWrite(dirPin2,HIGH);
    digitalWrite(dirPin3,HIGH);
    digitalWrite(dirPin4,HIGH);  

    analogWrite(pwmPin1, pwmVal);
    analogWrite(pwmPin2, pwmVal);
    analogWrite(pwmPin3, pwmVal);
    analogWrite(pwmPin4, pwmVal);
    delay(dtMotor);
  }
  
  if(xValR >= 505)
  {
    digitalWrite(dirPin1,LOW);   //Backward
    digitalWrite(dirPin2,LOW);
    digitalWrite(dirPin3,LOW);
    digitalWrite(dirPin4,LOW); 

    analogWrite(pwmPin1, pwmVal);
    analogWrite(pwmPin2, pwmVal);
    analogWrite(pwmPin3, pwmVal);
    analogWrite(pwmPin4, pwmVal);
    delay(dtMotor);
  }

  if(yValR <= 505) //Left Turn
  {
    digitalWrite(dirPin1,LOW);   //Backward
    digitalWrite(dirPin2,LOW);
    digitalWrite(dirPin3,HIGH);  //Forward
    digitalWrite(dirPin4,HIGH);     

    analogWrite(pwmPin1, pwmVal);
    analogWrite(pwmPin2, pwmVal);
    analogWrite(pwmPin3, pwmVal);
    analogWrite(pwmPin4, pwmVal);
    delay(dtMotor);
  }
  
  if(yValR >= 525) //Right Turn
  {
    digitalWrite(dirPin1,HIGH);   //Forward
    digitalWrite(dirPin2,HIGH);
    digitalWrite(dirPin3,LOW);    //Backward
    digitalWrite(dirPin4,LOW);     

    analogWrite(pwmPin1, pwmVal);
    analogWrite(pwmPin2, pwmVal);
    analogWrite(pwmPin3, pwmVal);
    analogWrite(pwmPin4, pwmVal);
    delay(dtMotor);
  }

  if(xValR>=490 && xValR<=510 && yValR<=525 && yValR>=505)
  {
    analogWrite(pwmPin1, 0);
    analogWrite(pwmPin2, 0);
    analogWrite(pwmPin3, 0);
    analogWrite(pwmPin4, 0);
    delay(dtMotor);
  }
}
