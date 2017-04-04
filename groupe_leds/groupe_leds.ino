int ledPin0 = 6;
int ledPin1 = 7;
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;

void setup() {
 pinMode(ledPin0, OUTPUT);
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 pinMode(ledPin3, OUTPUT);
 pinMode(ledPin4, OUTPUT);
 pinMode(ledPin5, OUTPUT);
}

void loop() {
 upAll();
 delay(3000);
 downAll();
 delay(3000);
}

void upAll(){
 digitalWrite(ledPin0, HIGH);
 digitalWrite(ledPin1, HIGH);
 digitalWrite(ledPin2, HIGH);
 digitalWrite(ledPin3, HIGH);
 digitalWrite(ledPin4, HIGH);
 digitalWrite(ledPin5, HIGH);
}

void downAll(){
 digitalWrite(ledPin0, LOW);
 digitalWrite(ledPin1, LOW);
 digitalWrite(ledPin2, LOW);
 digitalWrite(ledPin3, LOW);
 digitalWrite(ledPin4, LOW);
 digitalWrite(ledPin5, LOW);
}
