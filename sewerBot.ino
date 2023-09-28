#include <Servo.h>

#define xPin A1
#define yPin A0
#define sPin 2

int xVal = 0;
int yVal = 0;
int sVal = 0;

int dt = 15;

Servo servoPan;
Servo servoTilt;

int posPan = 90; //xVal Map
int posTilt = 150; //yVal Map

void setup()
{
  //Serial.begin(115200);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT_PULLUP);

  servoPan.attach(4);
  servoTilt.attach(3);
  servoPan.write(posPan);
  servoTilt.write(posTilt);
}

void loop()
{
  joyStick();
  servoBracket();
}
