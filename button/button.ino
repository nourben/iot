
int led = 9;
int state;

void setup() {
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
    Serial.begin(12600);
}

void loop() {
    state = digitalRead(led);
    if (state == HIGH)
      Serial.print("Haut\n");
    else
      Serial.print("Bas\n");
}

