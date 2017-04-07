#include <VirtualWire.h>

//---------------------------
//Ultrason Part
int trig = 12;
int echo = 13;
long lecture_echo;
long cm;

//---------------------------
//Radio Part
int radioDataPin = 3;

//---------------------------
//Digital_Display Part
int ledPinDP = 4; //dp
int ledPinC = 5; //c
int ledPinB = 6; //b
int ledPinA = 7; //a
int ledPinF = 8; //f
int ledPinG = 9; //g
int ledPinE = 10; //e
int ledPinD = 11; //d

//---------------------------
//Button Part
int pinBtn = 2;
int buttonState = 0;
int parkingSpotNumber = 0;

//---------------------------
//Global Part
String prefixMsg = "PARK-IOT_";
bool logVal = false;
int distanceDetection = 40; //(en centimetres)
int delayBeforeDetection = 5000; //(en millisecondes)
int cars[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int isFirst[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//---------------------------
//---------------------------
/*
 * Initialisation
 */
void setup()
{
  Serial.begin(9600);
  
  //Radio
  vw_set_ptt_inverted(true); // Required by the RF module
  vw_setup(2000); // bps connection speed
  vw_set_tx_pin(radioDataPin);

  //Ultrasounds
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);

  //Digital Display
  pinMode(ledPinDP, OUTPUT);
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinC, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  pinMode(ledPinE, OUTPUT);
  pinMode(ledPinF, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  
  //Button
  pinMode(pinBtn, INPUT);

  //Init Segment Display
  int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinE, ledPinF, ledPinDP};
  draw(MyArray);
}

/*
 * Boucle principale du programme
 */
void loop()
{
  if(logVal){
    Serial.println("-----------------");
    Serial.println("StartLoop");
  }

  buttonManager();
  analysis();
  
  delay(300);
}


/*
 * Traitement vérifiant la disponibilité des places
 */
void analysis(){


  if(logVal){
    Serial.print("vehicule :");
    Serial.println(parkingSpotNumber);
  
    Serial.print("etat :");
    Serial.println(cars[parkingSpotNumber]);
  }
   
  int firstDistance = getDistance();
  int secondDistance = 0;

  //Si on detecte un objet dans la distance definie
  //if(firstDistance < distanceDetection ){
  if(firstDistance < distanceDetection && cars[parkingSpotNumber] == 0){
    
    //On attend la durée définie puis on reverifie que le vehicule detecté est toujours la
    if(logVal){Serial.println("Delai avant seconde verification");}
    delay(delayBeforeDetection);

    secondDistance = getDistance();
    //Si le véhicule detecté est toujours la
    if(secondDistance < distanceDetection){
      
      //Envoi msg pour dire que la place est prise
      cars[parkingSpotNumber] = 1;
      sendMessage(parkingSpotNumber, secondDistance);
    }
  }
  //Si on ne detecte pas d'objet dans la distance definie
  //else if(firstDistance > distanceDetection){
  else if(firstDistance > distanceDetection && cars[parkingSpotNumber] == 1){
    
    //On attend la durée définie puis on reverifie qu'il n'y a toujours rien dans la distance définie
    if(logVal){Serial.println("Delai avant seconde verification");}
    delay(delayBeforeDetection);

    secondDistance = getDistance();
    //Si on ne detecte toujours rien
    if(secondDistance > distanceDetection){
      
      //Envoi msg pour liberer la place
      cars[parkingSpotNumber] = 0;
      sendMessage(parkingSpotNumber, secondDistance);
    }
  }
}


//--------------------------------------------------------
//    Bouton
//--------------------------------------------------------

/*
 * Met .a jour l'affichage et le numero de la place de ârking a chaque fois que le bouton est pressé
 */
void buttonManager(){
  //Recuperation de l'etat du bouton
  buttonState = digitalRead(pinBtn);
  /*
   if(logVal){
    Serial.println("buttonState : ");
    Serial.println(buttonState);
  }
  */
  
  //Si le boutton est presse
  if (buttonState == HIGH) {
    /*
    if(logVal){
      Serial.print("parkingSpotNumber : ");
      Serial.println(parkingSpotNumber);
    }      
    */

      if(parkingSpotNumber < 9)
      {
        parkingSpotNumber = parkingSpotNumber+1;
      }
      else if(parkingSpotNumber == 9)
      {
        parkingSpotNumber = 0;
      }
      
      if(parkingSpotNumber == 0){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinE, ledPinF, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 1){
        int MyArray[7] = {ledPinB, ledPinC, ledPinDP, ledPinDP, ledPinDP, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 2){
        int MyArray[7] = {ledPinA, ledPinB, ledPinG, ledPinE, ledPinD, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 3){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinG, ledPinD, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 4){
        int MyArray[7] = {ledPinF, ledPinB, ledPinG, ledPinC, ledPinDP, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 5){
        int MyArray[7] = {ledPinA, ledPinF, ledPinG, ledPinC, ledPinD, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 6){
        int MyArray[7] = {ledPinA, ledPinF, ledPinG, ledPinE, ledPinC, ledPinD, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 7){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinDP, ledPinDP, ledPinDP, ledPinDP};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 8){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinE, ledPinF, ledPinG};
        draw(MyArray);
      }
      else if(parkingSpotNumber == 9){
        int MyArray[7] = {ledPinA, ledPinB, ledPinC, ledPinD, ledPinF, ledPinG, ledPinDP};
        draw(MyArray);
      }
  }
  
}


//--------------------------------------------------------
//    Ultrasons
//--------------------------------------------------------

/*
 * Recuperation de la distance mesurée par le capteur ultrason
 */
int getDistance()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);

  //Récuperation de la distance mesurée par le capteur ultrason
  lecture_echo = pulseIn(echo, HIGH);

  //Conversion en cm
  cm = lecture_echo / 58;
  if(logVal){
    Serial.print("Distance :");
    Serial.println(cm);
  }

  return cm;
}



//--------------------------------------------------------
//    Digital display
//--------------------------------------------------------
/*
 * Allume les broches/branches du composant
 */
void draw(int TheArray[])
{
  turnOffAll();
  for(int i = 0; i < 8; i++){
    digitalWrite(TheArray[i], HIGH);  
  }
}

/*
 * Eteint toutes les broches/branches
 */
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

//--------------------------------------------------------
//    Radio
//--------------------------------------------------------

/*
 * Envoi d'un message radio
 */
void sendMessage(int parkingNumber, int ditanceRadio )
{ 

  //isFirst[parkingNumber] = 1;
  
  //Construction de la chaine a envoyer
  String messageStr = prefixMsg;
  messageStr += String(parkingNumber) + "_";
  messageStr += String(ditanceRadio);

  int str_len = messageStr.length() + 1; 
  char charMsg[str_len];
  messageStr.toCharArray(charMsg, str_len);

  //Envoi du message
  vw_send((uint8_t *)charMsg, strlen(charMsg));
  vw_wait_tx();
  
  if(logVal){
    Serial.print("Sending message : ");
    Serial.println(messageStr);
  }
}

