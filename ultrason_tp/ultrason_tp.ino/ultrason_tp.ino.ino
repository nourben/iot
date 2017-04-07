int trig = 12;
int echo = 13;
long lecture_echo;
long cm;

void setup() {
  Serial.begin (9600);

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
}

void loop() {
    Serial.println("-----------------");
    Serial.println("StartLoop");

  digitalWrite(trig, HIGH);  // Added this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trig, LOW);

  lecture_echo = pulseIn(echo, HIGH);
  cm = lecture_echo / 58;
  Serial.print("Distance :");
  Serial.println(cm);
  delay(1000);
} 
