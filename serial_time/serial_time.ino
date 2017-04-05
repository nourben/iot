unsigned long time2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println(" OK init finish");  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Time: ");
  time2 = millis();
  
  //prints time since program started
  Serial.println(time2);
  
  // wait a second so as not to send massive amounts of data
  delay(1000);
}
