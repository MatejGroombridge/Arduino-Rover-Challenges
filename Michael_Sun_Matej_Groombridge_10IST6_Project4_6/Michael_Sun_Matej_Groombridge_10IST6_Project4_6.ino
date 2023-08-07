// import HMsoft
#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3

// Motor One
char key;
char input;
int enA = 12;
int in1 = 11;
int in2 = 10;

// Motor Two
int enB = 7;
int in3 = 9;
int in4 = 6;

// Ultrasonic Sensors
const int trigPin = 3;
const int echoPin = 2;

int duration = 0;
long cm = 0;
int revSpeed = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  HM10.begin(9600);

}

void goForward() {
    revSpeed = 100;
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
    Serial.println("Motors Forward!");
    delay(500);
    revSpeed = -1;
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
}
void goBackward() {
    revSpeed = 100;
    analogWrite(in2, revSpeed);
    analogWrite(in4, revSpeed);
    Serial.println("Motors Backward!");
    delay(500);
    revSpeed = -1;
    analogWrite(in2, revSpeed);
    analogWrite(in4, revSpeed);
}
void goLeft() {
    revSpeed = 100;
    analogWrite(in3, revSpeed);
    analogWrite(in2, revSpeed);
    Serial.println("Motors Left!");
    delay(370);
    revSpeed = -1;
    analogWrite(in2, revSpeed);
    analogWrite(in3, revSpeed);
}
void goRight() {
    revSpeed = 100;
    analogWrite(in4, revSpeed);
    analogWrite(in1, revSpeed);
    Serial.println("Motors Right!");
    delay(370);
    revSpeed = -1;
    analogWrite(in4, revSpeed);
    analogWrite(in1, revSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5000);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10000);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = duration * 0.034/2;

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println("cm");

  HM10.listen();  // listen the HM10 port

  while (HM10.available() > 0) {   // if HM10 sends something then read
    key = HM10.read();
    
    if (key == 'w') {          
      goForward();
    }
    else if (key == 'a') {
      goLeft();
    }
    else if (key == 's') {
      goBackward();
    }
    else if (key == 'd') {
      goRight();
    }
  }
}
