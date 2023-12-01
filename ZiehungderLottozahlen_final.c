//Ziehung der Lottozahlen
//In diesem Programm wird ein Lottospiel simuliert. Es werden vom Nutzer 6 aus 49 getippt, anschlie�end werden 6 zuf�llige Zahlen generiert und die Gewinnquote bestimmt.
//Anna Katharina Becker, Finn-Niklas Zymelka, Nele Hetzer 
//01.12.2023
//Version 4

#define _CRT_SECURE_NO_WARNINGS                                             //Warnungen vom Kompiler werden unterdr�ckt 

#include <stdio.h>                                                          //Bibliotheken
#include <stdlib.h>
#include <time.h>


short getShort(char text[], short min, short max);                          //Funktionsdeklaration der ausgelagerten Funktion zur �berpr�fung der vom Nutzer eingegebenen Zahl

int main(void) {                                                            //Hauptfunktion


    printf("Dies ist eine Simulation eines Lottospiels. Es werden 6 aus 49 getippt. Mit etwas Glueck koennen auch Sie gewinnen!\n\n"); //Information an den Nutzer 
    
    //Aufgabe 1 und 2 (short Funktion)

    printf("Bitte geben sie 6 ganze Zahlen zwischen 1 und 49 fuer ihren Lottotipp ein. \n");    //Aufforderung an der Nutzer 
    char text[] = "Zahl";                                                   //Deklaration f�r die short Funktion
    short min = 1;                                                          //untere Grenze 
    short max = 49;                                                         //obere Grenze
    short ZahlenVomNutzer[6];                                               
    short aktuellerTip = 1;

    //Aufgabe 3 - Abfrage der Lottozahlen vom Nutzer 

    for (int i = 0; i < 6; i++) {                                           //Definitionsbereich der Variable i
        short input;                                                        //Variablendefinition
        int isValidInputNumber;

        do {
            isValidInputNumber = 0;                                         //true-false Bedingung 0 = false
            printf("Sie tippen gerade Ihre %d ", aktuellerTip);             //Ausgabe an den Nutzer
            input = getShort("Zahl: ", min, max);                           //Anforderungen werden in getshort �berpr�ft

            int valueAlreadyExists = 0;                                     //Variable wird auf false gesetzt

            for (int j = 0; j < i; j++) {                                   //Definitionsbereich j
                if (ZahlenVomNutzer[j] == input) {                          //Zahl wird auf Dopplung gepr�ft 
                   
                    printf("Die Zahl haben Sie bereits getippt. Bitte geben Sie eine andere Zahl ein\n");       //Ausgabe an den Nutzer 
                   
                    valueAlreadyExists = 1;                                 //Zahl wurde bereits getippt, doppelte Eingabe nicht m�glich 
                }
            }

            if (valueAlreadyExists == 1){                                   //eingegebene Zahl exisitiert bereits (true)
                 isValidInputNumber = 0;                                    //keine g�ltige Eingabe
             }
             else if (valueAlreadyExists == 0){                             //eingegebene Zahl existiert noch nicht (false)
                 isValidInputNumber = 1;                                    //g�ltige Eingabe
             }
            
          
        } while (!isValidInputNumber);                                      // nach �berpr�fung auf Dopplung wird Variable auf true gesetzt 

        aktuellerTip++;                                                     //springt zum n�chsten Tipp

        ZahlenVomNutzer[i] = input;                                         //Eingabe wird im array gespeichert 
    }


    printf("\nIhre ausgew�hlten Zahlen f�r den Lottotipp: ");               //eingegebene Zahlen werden aufgelistet ausgegeben 
    for (int i = 0; i < 6; i++) {                                           //Definitionsbereich 
        printf("%d ", ZahlenVomNutzer[i]);                                  //Ausgabe der im array gespeicherten Zahlen 
    }

    //Aufgabe 4 - Ziehung von 6 zuf�llig generierten Zahlen

    srand((unsigned int)time(NULL));                                        //Initialisierung 
    

    short ziehungLottozahlen[6];                                            //Deklaration
    for (int a = 0; a < 6; ++a) {                                           //Definitionsbereich der Variable a
        ziehungLottozahlen[a] = rand() % 49 + 1;                            //Bereich der zuf�llig generierten Zahlen, werden im array gespeichert 
    }
    printf("\n\nGezogene Lotttozahlen: ");                                  //Ausgabe an Nutzer 
    for (int a = 0; a < 6; ++a) {                                           //Definitionsbereich
        printf("%d ", ziehungLottozahlen[a]);                               //Ausgabe der im array gespeicherten Zahlen
    }


    //Aufgabe 5 - Anzahl der Richtigen bestimmen
    short AnzahlRichtige = 0;                                               //Deklaration
    for (int a = 0; a < 6; ++a) {                                           //Definitionsbereich f�r Variable a
        for (int i = 0; i < 6; i++) {                                       //Definitionsbereich f�r Variable i
            if (ziehungLottozahlen[a] == ZahlenVomNutzer[i]) {              //wenn Werte �bereinstimmen
                ++AnzahlRichtige;                                           //Anzahl Richtige wird erh�ht
                break;                                                      
            }
        }
    }
    printf("\n\n");                                                         
    printf("Anzahl Richtige: %d \n", AnzahlRichtige);                       //Anzahl Richtige werden ausgegeben


    if (AnzahlRichtige == 2) {                                              //Ermittlung des Gewinns und anschlie�ende Ausgabe
        printf("Ihr Gewinn liegt bei 5 Euro");
    }
    else if (AnzahlRichtige == 3) {
        printf("Ihr Gewinn liegt bei 50 Euro");
    }
    else if (AnzahlRichtige == 4) {
        printf("Ihr Gewinn liegt bei 1000 Euro");

    }
    else if (AnzahlRichtige == 5) {
        printf("Ihr Gewinn liegt bei 50.000 Euro");

    }
    else if (AnzahlRichtige == 6) {
        printf("JACKPOT !!! \nIhr Gewinn liegt bei 1.000.000 Euro");
    }
    else if (AnzahlRichtige < 2) {
        printf("Sie hatten diesmal leider kein Glueck");
    }

    return 0;

}

//Aufgabe 1 und 2 - ausgelagerte short Funktion
short getShort(char text[], short min, short max)                           //[in] question text for user input
{
    short value;                                                            // user input
    int finished = 0;                                                       // flag for correct user input
    char ch;                                                                // character behind number
    int retVal;                                                             // return value of scanf

    do {
        // get user input
        printf("%s: ", text);
        ch = '\0';                                                          //character definiert 
        retVal = scanf("%hd%c", &value, &ch);
        // check for valid user input
        if (retVal != 2) printf("Das war keine korrekte Zahl!\n");
        else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");
        else if (value < min || value > max) printf("Der gueltige Zahlenbereich ist ueberschritten\n"); //�berpr�fung der Zahl, ob sie im richtigen Zahlenbereich ist 
        else finished = 1;

        // clear input stream
        while (ch != '\n') scanf("%c", &ch);


        // repeat if not finished
    } while (!finished);

    // return user input
    return value;
}


