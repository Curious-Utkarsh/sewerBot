#include <Servo.h>
#include <U8g2lib.h>
#include <SPI.h>

#define sPinL A0

#define hsulSen A1 //hydrogen sulphide
#define ammoSen A2 //ammonia
#define methSen A3 //methane

#define yPinR A4
#define xPinR A5

#define yPinL A6
#define xPinL A7

#define svPan 9
#define svTilt 12

#define dirPin1 0
#define dirPin2 1
#define dirPin3 2
#define dirPin4 3

#define pwmPin1 4
#define pwmPin2 5
#define pwmPin3 6
#define pwmPin4 7

int xValL = 0; //For Servo
int yValL = 0;
int sValL = 0;

int xValR = 0; //For Motors
int yValR = 0;
int sValR = 0;

byte pwmVal = 255;

int methVal = 0;
float methConc = 0.0;

int ammoVal = 0;
float ammoConc = 0.0;

byte dtServo = 15;
byte dtMotor = 100;



Servo servoPan;
Servo servoTilt;

byte posPan = 100; //xVal Map
byte posTilt = 150; //yVal Map

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

void setup()
{
  Serial.begin(115200);
  
  u8g2.begin();
  
  pinMode(xPinL, INPUT);
  pinMode(yPinL, INPUT);
  pinMode(sPinL, INPUT_PULLUP);

  pinMode(xPinR, INPUT);
  pinMode(yPinR, INPUT);

  pinMode(methSen, INPUT);
  pinMode(ammoSen, INPUT);

  servoPan.attach(svPan);
  servoTilt.attach(svTilt);
  servoPan.write(posPan);
  servoTilt.write(posTilt);

  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(dirPin3,OUTPUT);
  pinMode(dirPin4,OUTPUT);
  
  pinMode(pwmPin1,OUTPUT);
  pinMode(pwmPin2,OUTPUT);
  pinMode(pwmPin3,OUTPUT);
  pinMode(pwmPin4,OUTPUT);
}

void loop()
{
  motorDrive();
  servoBracket();
  concDisplay();
}
