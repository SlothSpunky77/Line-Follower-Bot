#include <AFMotor.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <NewPing.h>

#define IR_Left 5
#define IR_Right 6
#define trig 12
#define echo 13
AF_DCMotor motor1(1);  //left
AF_DCMotor motor2(2);  //right
NewPing sonar(trig, echo);

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() 
{
  Serial.begin(9600);
  pinMode(IR_Left, INPUT);
  pinMode(IR_Right, INPUT);
  //pinMode(echo, INPUT);
  //pinMode(trig, OUTPUT);

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
}

void loop() 
{
  float red, green, blue;
  // put your main code here, to run repeatedly:
  int readLeft = digitalRead(IR_Left);
  int readRight = digitalRead(IR_Right);
  //Serial.println("infrared read");

  //long timeInMicro; //duration
  //long distanceInCm;  //distance
  int distance = sonar.ping_cm();
  delay(100);
  //Serial.println(distance);

  /*digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //Serial.println("trig read");
  timeInMicro= pulseIn(echo, HIGH);
  distanceInCm = (timeInMicro/29)/2;
  //Serial.println("ultrasound calculations done");
  //Serial.println(distanceInCm);
  delay(100); */
  
  tcs.setInterrupt(false);  // turn on LED
  delay(60);  // takes 50ms to read
  tcs.getRGB(&red, &green, &blue);
  tcs.setInterrupt(true);  // turn off LED
  
  if ((int(red) > 100) && (int(green) < 100) && (int(blue) < 100))
  {
    Serial.println("Red detected");
    Stop();
  }

  else if (distance < 15)
  {
    Serial.println("Stopped (Ultrasound).");
    Stop();
  }
  
  else if (readLeft == 0 && readRight == 0)
  {
    Serial.println("Moving forward.");
    Forward();
  }
  else if (readLeft == 1 && readRight == 1)
  {
    Serial.println("Stopped (Infrared).");
    Stop();
  }
  else if (readLeft == 1 && readRight == 0)
  {
    Serial.println("Right.");
    Right();
  }
  else if (readLeft == 0 && readRight == 1)
  {
    Serial.println("Left.");
    Left();
  }
}

void Forward() 
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void Backward() 
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void Right() 
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.setSpeed(150);
  motor1.run(FORWARD);
}

void Left() 
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor2.setSpeed(150);
  motor2.run(FORWARD);
}

void Stop() 
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
}
