#include <Servo.h>
#define TRIGGER_PIN 5
#define ECHO_PIN 6

Servo leftservo, rightservo;
int button1 = 3;
int button2 = 4;

void setup() {
  leftservo.attach(9);
  rightservo.attach(10);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    while(1){
    if(digitalRead(button2)== LOW){
      break;
    }
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    int distance = duration * 0.034 / 2;

    if (distance <= 15) {
      leftservo.write(50);
      rightservo.write(50);
      delay(500);
      }
    else{
      leftservo.write(180);
      rightservo.write(0);
      delay(100);
    }
    
    }
    
    }
    
  }

