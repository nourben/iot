//int ledPin1 = 7;
//int ledPin2 = 2;
//int ledPin3 = 3;
//int ledPin4 = 4;
//int ledPin5 = 5;
//int ledPin6 = 6;
//int ledPin7 = 8;
//int ledPin8 = 9;

int ledPin0 = 0;
int ledPin1 = 1;
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;
int ledPin6 = 6;
int ledPin7 = 7;
int ledPin8 = 8;
int ledPin9 = 9;
int ledPin10 = 10;
int ledPin11 = 11;
int ledPin12 = 12;
int ledPin13 = 13;
int ledPin14 = 14;
int ledPin15 = 15;

void setup() {
  //pinMode(ledPin0, OUTPUT);
  //pinMode(ledPin1, OUTPUT);
  //pinMode(ledPin2, OUTPUT);
  //pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  //pinMode(ledPin12, OUTPUT);
  //pinMode(ledPin13, OUTPUT);
  //pinMode(ledPin15, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Heyoooo");

  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
  digitalWrite(ledPin7, HIGH);
  digitalWrite(ledPin8, LOW);
  digitalWrite(ledPin9, HIGH);
  digitalWrite(ledPin10, HIGH);
  digitalWrite(ledPin11, LOW);
}

