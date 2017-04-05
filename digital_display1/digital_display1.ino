int ledPinDP = 4; //dp
int ledPinC = 5; //c
int ledPinB = 6; //b
int ledPinA = 7; //a
int ledPinF = 8; //f
int ledPinG = 9; //g
int ledPinE = 10; //e
int ledPinD = 11; //d

int pinBtn = 2;
int buttonState = 0;
int number = 0;

void setup() {
  pinMode(pinBtn, INPUT);

  pinMode(ledPinDP, OUTPUT);
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
   buttonState = digitalRead(pinBtn);
     //Serial.print("buttonState : ");
     //Serial.println(buttonState);
     
  if (buttonState == HIGH) {
    if(number == 10)
      number = 0;
      /*
      Serial.println("-----------");
      Serial.println(number);
      Serial.println(" ");
      */    
      if(number == 0){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinE, ledPinF, ledPinDP};
        draw(MyArray);
      }
      else if(number == 1){
        int MyArray[7] = {ledPinB, ledPinC, ledPinDP, ledPinDP, ledPinDP, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(number == 2){
        int MyArray[7] = {ledPinA, ledPinB, ledPinG, ledPinE, ledPinD, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(number == 3){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinG, ledPinD, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(number == 4){
        int MyArray[7] = {ledPinF, ledPinB, ledPinG, ledPinC, ledPinDP, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(number == 5){
        int MyArray[7] = {ledPinA, ledPinF, ledPinG, ledPinC, ledPinD, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(number == 6){
        int MyArray[7] = {ledPinA, ledPinF, ledPinG, ledPinE, ledPinC, ledPinD, ledPinDP};
        draw(MyArray);
      }
      else if(number == 7){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinDP, ledPinDP, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(number == 8){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinE, ledPinF, ledPinG};
        draw(MyArray);
      }
      else if(number == 9){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinF, ledPinG, ledPinDP};
        draw(MyArray);
      }
      number = number+1;
      delay(600);
  }

}

void draw(int TheArray[])
{
  turnOffAll();
  for(int i = 0; i < 8; i++){
    digitalWrite(TheArray[i], HIGH);  
  }
}

void turnOffAll(){
  //digitalWrite(ledPinDP, LOW);
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);
  digitalWrite(ledPinC, LOW);
  digitalWrite(ledPinD, LOW);
  digitalWrite(ledPinE, LOW);
  digitalWrite(ledPinF, LOW);
  digitalWrite(ledPinG, LOW);
}


