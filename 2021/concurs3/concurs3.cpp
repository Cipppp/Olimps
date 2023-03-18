#include <fstream>  // Biblioteca pentru fisiere
#include <iostream>

using namespace std;  // <-- il adaugam mereu

int main() {
    ifstream input("concurs.in");    // Deschidem fisierul de citire
    ofstream output("concurs.out");  // Deschidem fisierul de afisare

    int tipulCerintei, dimensiune;

    // Citim tipul cerintei si dimensiunea
    input >> tipulCerintei;
    input >> dimensiune;

    // Declaram o lista in care stocam echipele si concurentii nostrii
    int echipe[dimensiune], concurenti[dimensiune];

    // Citim fiecare element din fisier
    for (int index = 1; index <= dimensiune; index++) {
        input >> echipe[index];
        input >> concurenti[index];
    }

    // Verificam tipul cerintei
    if (tipulCerintei == 1) {
        int punctajMaxim = 0;
        int punctajeEgale = 0;
        for (int index = 1; index <= dimensiune; index++) {
            int punctajConcurent = 0;
            // Cat timp numarul nu este 0 calculam punctajul unui concurent
            while (concurenti[index] != 0) {
                // Verificam daca numarul 10 se afla in numarul nostru
                if (concurenti[index] % 10 == 0 && concurenti[index] / 10 % 10) {  // Verificam daca ultima cifra este 0 si penultima cifra este 1
                    punctajConcurent += 10;
                    concurenti[index] = concurenti[index] / 100;
                } else {
                    punctajConcurent += concurenti[index] % 10;
                    concurenti[index] = concurenti[index] / 10;
                }
            }

            // Verificam daca avem un concurent cu punctaj mai mare decat cel maxim
            if (punctajConcurent > punctajMaxim) {
                punctajMaxim = punctajConcurent;
                punctajeEgale = 1;
                // Daca avem un concurent cu acelasi punctaj crestem numarul de punctaje egale
            } else if (punctajConcurent == punctajMaxim) {
                punctajeEgale++;
            }
        }
        output << punctajMaxim << " " << punctajeEgale;
    } else if (tipulCerintei == 2) {
        // Initalizam puncatjele echipelor
        int punctajechipe[3] = {0};

        // Parcurgem toate echipele
        for (int index = 1; index <= dimensiune; index++) {
            int punctajConcurent = 0;
            // Cat timp punctajul concurentului nu este 0, calculam punctajul unui concurent
            while (concurenti[index] != 0) {
                // Verificam daca numarul 10 se afla in numarul nostru
                if (concurenti[index] % 10 == 0 && concurenti[index] / 10 % 10) {  // Verificam daca ultima cifra este 0 si penultima cifra este 1
                    punctajConcurent += 10;
                    concurenti[index] = concurenti[index] / 100;
                } else {
                    punctajConcurent += concurenti[index] % 10;
                    concurenti[index] = concurenti[index] / 10;
                }
            }

            // Adaugam in lista, punctajul echipei din care face parte concurentul
            punctajechipe[echipe[index]] += punctajConcurent;
        }

        int punctajEchipaMaxim = 0, echipa = 0;

        // Cautam echipa cu cel mai mare punctaj
        for (int index = 0; index <= 2; index++) {
            if (punctajechipe[index] > punctajEchipaMaxim) {
                punctajEchipaMaxim = punctajechipe[index];
                echipa = index + 1;
            }
        }

        output << echipa << " " << punctajEchipaMaxim;
    }
}
