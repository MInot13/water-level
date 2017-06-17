/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 12 Trig to Arduino pin 11
 */

#define trigPin 11
#define echoPin 12
int i=0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay(500);
  if(Serial.available() > 0){
  i = Serial.read();
  if(i==1){
  distance=110-(distance-15);
  
  Serial.println(distance);
  }
  }
}
