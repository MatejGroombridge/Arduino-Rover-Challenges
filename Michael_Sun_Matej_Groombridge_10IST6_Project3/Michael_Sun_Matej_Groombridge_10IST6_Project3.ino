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
int revSpeed = 100;
// Ultrasonic Sensors

int duration = 0;
long cm = 0;


void setup() {
  Serial.begin(9600);
  
  Serial.println("Type Something: ");
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
    delay(375);
    revSpeed = -1;
    analogWrite(in4, revSpeed);
    analogWrite(in1, revSpeed);
}

void loop() {
  if (Serial.available() > 0) {
    key = Serial.read();
    
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
