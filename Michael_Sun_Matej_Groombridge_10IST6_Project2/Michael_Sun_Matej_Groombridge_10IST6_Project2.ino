// Motor One
int enA = 12;
int in1 = 11;
int in2 = 10;

// Motor Two
int enB = 7;
int in3 = 9;
int in4 = 10;

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

  if (cm > 5 && cm < 50) {
    revSpeed = map(cm, 5, 50, 100, 1000);
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
    delay(100);
    Serial.print(revSpeed);
  } 
  else if (cm > 50 && cm < 100) {
    revSpeed = map(cm, 50, 100, 500, 2000);
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
    delay(100);
    Serial.print(revSpeed);
  } 
  else if (cm > 100) {
    revSpeed = map(cm, 100, 1000, 1000, 2000);
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
    delay(100);
    Serial.print(revSpeed);
  } 
  else if (cm < 6) {
    revSpeed = -1;
    analogWrite(in1, revSpeed);
    analogWrite(in3, revSpeed);
    delay(100);
    Serial.print(revSpeed);
  }
}
