#include <fstream>  // Biblioteca pentru fisiere
#include <iostream>

using namespace std;  // <-- il adaugam mereu

int main() {
    ifstream input("sir.in");    // Deschidem fisierul de citire
    ofstream output("sir.out");  // Deschidem fisierul de afisare

    int tipulCerintei, dimensiune, rezultat, maxim = 0;

    // Citim tipul cerintei si dimensiunea
    input >> tipulCerintei;
    input >> dimensiune;

    // Declaram o lista in care stocam elementele noastre
    int numere[dimensiune];

    // Citim fiecare element din fisier
    for (int index = 1; index <= dimensiune; index++) {
        input >> numere[index];
    }

    // Verificam tipul cerintei
    if (tipulCerintei == 1) {
        for (int index = dimensiune; index >= 1; index--) {
            if (numere[index] < numere[index - 1]) {
                rezultat = index - 1;
            } else {
                break;
            }
        }
        output << rezultat;
    } else if (tipulCerintei == 2) {
        // Cautam pozitiile care au toate numerele din stanga mai mici
        for (int index = 1; index <= dimensiune - 1; index++) {
            if (numere[index] > maxim) {
                output << index << " ";
            }

            if (maxim < numere[index]) {
                maxim = numere[index];
            }
        }
    } else if (tipulCerintei == 3) {
        // Cautam maximul
        for (int index = 1; index <= dimensiune; index++) {  // Parcurgere sir de elemente
            // Verificam daca numarul din sir este mai mare decat maximul global, daca este mai mare actualizam maximul
            if (numere[index] > maxim) {
                maxim = numere[index];
            }
        }

        int primaAparitie = -1, ultimaApritie = -1;

        for (int index = 1; index <= dimensiune; index++) {
            // Verificam daca primaAparitie a fost gasita
            if (numere[index] == maxim) {
                if (primaAparitie == -1) {  // Daca nu am gasit prima pozitie a lui maxim
                    primaAparitie = index;
                } else if (ultimaApritie == -1) {  // Daca nu am gasit ultima pozitie a lui maxim
                    ultimaApritie = index;
                }
            }
        }
        int sumaNecesara = 0;
        // numere = [3 2 2 5 3 1 5 4]
        // maxim = 5
        // primaAparitie = 4
        // ultimaAparitie = 7
        // index = 7

        // Calculam doar intre intervalul dintre numerele maxime
        for (int index = primaAparitie; index <= ultimaApritie; index++) {
            sumaNecesara = sumaNecesara + (maxim - numere[index]);  // La suma anterioara adunam complementarul pana la maxim
        }

        // Afisam suma necesara
        output << sumaNecesara;
    }
}
