#include <VirtualWire.h>

String prefixMsg = "PARK-IOT_";
int distanceDetection = 40; //(en centimetres)

void setup()
{
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_rx_pin(3);
  vw_rx_start(); 
}
 
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen))
  {
    int i;
    String data;
    char test[buflen];
    
    for (i = 0; i < buflen; i++)
    {
      test[i] = buf[i];
    }
    
    test[i] = 0;
    data = String(test);

    if(data.startsWith(prefixMsg))
    {
      String message = data.substring(9); //Retire le prefixe
      int underscorePos = message.indexOf("_"); //Recupere la position de l'underscore restant

      String parkingSpot = message.substring(0, underscorePos);
      String distance = message.substring(underscorePos+1, sizeof(message)); //Distance en centimetres

      String isFree = "";
      if(distance.toInt() > distanceDetection)
      {
        isFree = "True";
      }
      else
      {
        isFree = "False";
      }
      
      String sendMsg = prefixMsg + parkingSpot;
      sendMsg+= "_" + isFree;
      
      Serial.println(sendMsg); 
    }
  }
}
