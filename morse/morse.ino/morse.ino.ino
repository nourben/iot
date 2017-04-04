
int led = 2;
int c=0;
int i=0, j=0;
int myIndex=0;
char myWord[6] = "salut";
int tab[36][5] = {
    {1, 2, 0, 0, 0}, //A
    {2, 1, 1, 1, 0},
    {2, 1, 2, 1, 0},
    {2, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 2, 1, 0},
    {2, 2, 1, 0, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 0, 0, 0},
    {1, 2, 2, 2, 0},
    {2, 1, 2, 0, 0},
    {1, 2, 1, 1, 0},
    {2, 2, 0, 0, 0},
    {2, 1, 0, 0, 0},
    {2, 2, 2, 0, 0},
    {1, 2, 2, 1, 0},
    {2, 2, 1, 2, 0},
    {1, 2, 1, 0, 0},
    {1, 1, 1, 0, 0},
    {2, 0, 0, 0, 0},
    {1, 1, 2, 0, 0},
    {1, 1, 1, 2, 0},
    {1, 2, 2, 0, 0},
    {2, 1, 1, 2, 0},
    {2, 1, 2, 2, 0},
    {2, 2, 1, 1, 0}, //Z
    {2, 2, 2, 2, 2}, //0
    {1, 2, 2, 2, 2},
    {1, 1, 2, 2, 2},
    {1, 1, 1, 2, 2},
    {1, 1, 1, 1, 2},
    {1, 1, 1, 1, 1},
    {2, 1, 1, 1, 1},
    {2, 2, 1, 1, 1},
    {2, 2, 2, 1, 1},
    {2, 2, 2, 2, 1}//9
};
void setup() {
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for(i=0; i<5; i++){
        c = myWord[i];
        Serial.print("\nLa lettre est ");
        Serial.print(c);
        if(c >47 && c < 58){
            myIndex = c-48;
        }
        else if(c>96 && c<123){
            myIndex = c-97;
        }
        for(j=0; j<5 && tab[myIndex][j] != 0; j++){
            if(tab[myIndex][j] == 1){
                Serial.print("\npoint");
                point();
            }
            else if(tab[myIndex][j] == 2){
                Serial.print("\nligne");
                line();
            }
            delay(500);
        }
        delay(1500);
        
        Serial.print("\n\n-- Fin de la lettre --\n");
    }
}


void point(){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
}

void line(){
    digitalWrite(led, HIGH);
    delay(1500);
    digitalWrite(led, LOW);
}
