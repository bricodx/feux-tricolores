//**************** Entête déclarative *******
// --- constantes des broches ---

const int ROUGE_1=2; //declaration constante de broche
const int ORANGE_1=3; //declaration constante de broche
const int VERT_1=4; //declaration constante de broche
const int ROUGE_2=5; //declaration constante de broche
const int ORANGE_2=6; //declaration constante de broche
const int VERT_2=7; //declaration constante de broche
const int DERANG=1; //declaration constante de broche

static uint32_t tempomode = millis(); ; // variable memoire de temps de changement de mode

int modefeu = 0 ; //0 pour feu en dérangement et 1 pour feu en mode normale

void setup()   { // debut de la fonction setup()

// ------- Brochage -------
pinMode(DERANG, INPUT); //met la broche en entree
pinMode(ROUGE_1, OUTPUT); //met la broche en sortie
pinMode(VERT_1, OUTPUT); //met la broche en sortie
pinMode(ORANGE_1, OUTPUT); //met la broche en sortie
pinMode(ROUGE_2, OUTPUT); //met la broche en sortie
pinMode(VERT_2, OUTPUT); //met la broche en sortie
pinMode(ORANGE_2, OUTPUT); //met la broche en sortie

//------- initialisation des LEDs au début = feu 1 au rouge et feu 2 au vert
digitalWrite(ROUGE_1,LOW); // met la broche au niveau BAS
digitalWrite(VERT_1,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_1,HIGH); // met la broche au niveau HAUT
digitalWrite(ROUGE_2,LOW); // met la broche au niveau BAS
digitalWrite(VERT_2,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_2,HIGH); // met la broche au niveau HAUT
delay(500); // pause de 0,5 seconde
digitalWrite(ORANGE_1,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_2,LOW); // met la broche au niveau BAS
delay(500); // pause de 0,5 seconde
digitalWrite(ORANGE_1,HIGH); // met la broche au niveau HAUT
digitalWrite(ORANGE_2,HIGH); // met la broche au niveau HAUT
delay(500); // pause de 0,5 seconde
digitalWrite(ORANGE_1,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_2,LOW); // met la broche au niveau BAS

}

void loop(){ // debut de la fonction loop()
//lecture action bouton
if (modefeu == 0) {
            if ((millis()-tempomode)>= 300000) { //variable temps de derangement 5min
                    modefeu = 1 ;
                    tempomode = millis() ;
            }
}

if (modefeu == 1) {
            if ((millis()-tempomode)>= 1200000) { //variable temps de normal 20min
                    modefeu = 0 ;
                    tempomode = millis() ;
            }
}


if (modefeu == 0) { // feu en mode derangement
digitalWrite(ROUGE_1,LOW); // met la broche au niveau BAS
digitalWrite(VERT_1,LOW); // met la broche au niveau BAS
digitalWrite(ROUGE_2,LOW); // met la broche au niveau BAS
digitalWrite(VERT_2,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_1,HIGH); // met la broche au niveau HAUT
digitalWrite(ORANGE_2,HIGH); // met la broche au niveau HAUT
delay(1000); // pause de 1 seconde
digitalWrite(ORANGE_1,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_2,LOW); // met la broche au niveau BAS
delay(1000); // pause de 1 seconde
digitalWrite(ORANGE_1,HIGH); // met la broche au niveau HAUT
digitalWrite(ORANGE_2,HIGH); // met la broche au niveau HAUT
delay(1000); // pause de 1 seconde
digitalWrite(ORANGE_1,LOW); // met la broche au niveau BAS
digitalWrite(ORANGE_2,LOW); // met la broche au niveau BAS
delay(1000); // pause de 1 seconde
                        }
                        else {   //feu en mode normal
  //--- le feu 2 passe au vert
digitalWrite(ROUGE_1,HIGH); // allume rouge feu 1
digitalWrite(ROUGE_2,LOW); // éteint rouge feu 2
digitalWrite(VERT_2,HIGH); // allume vert feu 2

delay (5000); // pause longue 5 secondes

//--- le feu 2 passe à l'orange
digitalWrite(VERT_2,LOW); // éteint vert feu 2
digitalWrite(ORANGE_2,HIGH); // allume orange feu 2

delay (2000); // pause 2 secondes

//--- le feu 2 passe au rouge
digitalWrite(ORANGE_2,LOW); // éteint orange feu 2
digitalWrite(ROUGE_2,HIGH); // allume rouge feu 2

delay (1000); // pause courte 1 seconde

//--- le feu 1 passe au vert
digitalWrite(ROUGE_1,LOW); // éteint rouge feu 1
digitalWrite(VERT_1,HIGH); // allume vert feu 1

delay (5000); // pause longue 5 secondes

//--- le feu 1 passe à l'orange
digitalWrite(VERT_1,LOW); // éteint vert feu 1
digitalWrite(ORANGE_1,HIGH); // allume orange feu 1

delay (2000); // pause 2 secondes

//--- le feu 1 passe au rouge
digitalWrite(ORANGE_1,LOW); // éteint orange feu 1
digitalWrite(ROUGE_1,HIGH); // allume rouge feu 1

delay (1000); // pause courte 1 seconde
                      }

} // fin de la fonction loop()
