#include <fstream>  // Biblioteca pentru fisiere
#include <iostream>

using namespace std;  // <-- il adaugam mereu

int main() {
    ifstream input("cifmaxmin.in");    // Deschidem fisierul de citire
    ofstream output("cifmaxmin.out");  // Deschidem fisierul de afisare

    int dimensiune, contorNumerePare = 0, contorNumereImpare = 0, numarParMax = 0, numarImparMin = 999;

    // Citim dimensiunea
    input >> dimensiune;

    int numar;

    // Citim fiecare element din fisier
    for (int index = 1; index <= dimensiune; index++) {
        // Pentru fiecare numar initializam cifra maxima si cifra minima
        int cifraMax = 0, cifraMin = 9, numarFormat;
        // Citim numarul din fisier
        input >> numar;

        // Verificam daca avem un numar par sau un numar impar
        if (numar % 2 == 0) {
            // Cat timp numarul nu este 0
            while (numar != 0) {
                // Verificam daca ultima cifra din numar este mai mare decat cifra maxima sau mai mica decat cifra minima
                if (numar % 10 > cifraMax) {
                    cifraMax = numar % 10;
                } else if (numar % 10 < cifraMin) {
                    cifraMin = numar % 10;
                }
                numar = numar / 10;
            }

            // La numere pare mai intai o sa avem cifra maxima si dupa cifra minima
            numarFormat = cifraMax * 10 + cifraMin;

            // Daca este cel mai mare numar format
            if (numarFormat > numarParMax) {
                numarParMax = numarFormat;
            }

            // Contorizam cate numere pare avem
            contorNumerePare++;

        } else {
            // Cat timp numarul nu este 0
            while (numar != 0) {
                // Verificam daca ultima cifra din numar este mai mare decat cifra maxima sau mai mica decat cifra minima
                if (numar % 10 > cifraMax) {
                    cifraMax = numar % 10;
                } else if (numar % 10 < cifraMin) {
                    cifraMin = numar % 10;
                }

                numar = numar / 10;
            }

            // La numere impare mai intai o sa avem cifra minima si dupa cifra maxima
            numarFormat = cifraMin * 10 + cifraMax;

            // Daca este cel mai mic numar format
            if (numarFormat < numarImparMin) {
                numarImparMin = numarFormat;
            }

            // Contorizam cate numere impare avem
            contorNumereImpare++;
        }
    }

    // Afisam rezultatul dorit
    output << numarParMax << " " << contorNumerePare << " " << numarImparMin << " " << contorNumereImpare;

    return 0;
}