//www.elegoo.com

#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

int Echo = A4;
int Trig = A5;

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 255
#define turnSpeed 255
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void setup() {
  myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
}

void loop() {
    myservo.write(90);  //set servo position according to scaled value
    delay(500);
    middleDistance = Distance_test();

    if(middleDistance <= 50) {
      stop();
      myservo.write(10);
      delay(300);
      rightDistance = Distance_test();
      myservo.write(90);
      delay(300);
      myservo.write(180);
      delay(300);
      leftDistance = Distance_test();
      myservo.write(90);
      
      if(rightDistance > leftDistance) {
        right();
      }
      else if(rightDistance < leftDistance) {
        left();
      }
      else if((rightDistance <= 20) || (leftDistance <= 20)) {
        back();
      }
      else {
        forward();
      }
    }
    else {
        forward();
    }
}
