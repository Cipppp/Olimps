#include <math.h>

#include <fstream>  // Biblioteca pentru fisiere
#include <iostream>

using namespace std;  // <-- il adaugam mereu

int main() {
    ifstream input("codjoc.in");    // Deschidem fisierul de citire
    ofstream output("codjoc.out");  // Deschidem fisierul de afisare

    int dimensiune = 0, sumaTotala = 0;

    // Citim numarul din fisier
    int numar;
    input >> numar;

    // Facem o copie dupa numarul original
    int aux = numar;

    // Calculam cate cifre are numarul
    while (aux != 0) {  // Cat timp numarul este diferit de 0
        dimensiune++;
        aux /= 10;
    }

    for (int index = dimensiune; index >= 0; index--) {
        int delimitator = pow(10, index);  // Aflam cate cifre trebuie sa luam de la final
        sumaTotala = sumaTotala + (numar % delimitator);
    }

    output << sumaTotala;

    return 0;
}