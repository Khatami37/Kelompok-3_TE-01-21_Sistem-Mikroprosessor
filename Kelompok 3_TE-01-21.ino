/*-----------------------------------------------------
'     
'     TRIG --> Pin 7
'     ECHO --> Pin 6
'-----------------------------------------------------*/


//pin Ultrasonik
#define trigPin 7
#define echoPin 6
#define buzzer 2
#define ledAman 8
#define led1 9
#define led2 10
#define led3 11
#define sensorgas A0
int sensorThres = 400;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(ledAman, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
 
 pinMode(buzzer, OUTPUT); 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  int adagas = analogRead(sensorgas);
  if (distance >= 16) // mau jaraknya 16 cm 
  {
    digitalWrite(ledAman, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3,LOW);
  }
  else {
    digitalWrite(ledAman,LOW);
  }
  
  if (distance <= 15) 
  {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3,LOW);
  }
  
  if (distance < 10) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3,LOW);      
  } 
  
  if (distance < 5) {
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
}
 
  delay(500);

  if (adagas > sensorThres)
{
  digitalWrite(buzzer, HIGH);
}

else 
{
  digitalWrite(buzzer, LOW);
}
}
