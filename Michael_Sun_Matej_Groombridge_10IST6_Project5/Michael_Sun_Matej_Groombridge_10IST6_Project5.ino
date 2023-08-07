// Motor One
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

void turn() {
    revSpeed = 100;
    analogWrite(in3, revSpeed);
    analogWrite(in2, revSpeed);
    Serial.println("Motors Left!");
    delay(500);
    revSpeed = -1;
    analogWrite(in3, revSpeed);
    analogWrite(in2, revSpeed);
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

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

  if (cm < 10) {
    goBackward();
    delay(500);
    turn();
    delay(500);
  } 
  else {
    revSpeed = 100;
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
    Serial.println("Motors Forward!");
    delay(500);
  }
}
