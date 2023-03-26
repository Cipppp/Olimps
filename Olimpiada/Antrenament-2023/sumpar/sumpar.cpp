#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("sumpar.in");
    ofstream fout("sumpar.out");

    // Citim dimensiunea vectorului
    int dimensiune;
    fin >> dimensiune;

    int suma = 0;

    // Citim numerele din fisier
    for (int index = 0; index < dimensiune; index++) {
        int numar;
        fin >> numar;
        // Verificam daca este numar par si are 3 cifre.
        if (numar % 2 == 0 && numar >= 100 && numar <= 999) {
            suma += numar;
        }
    }

    // Scriem suma in fisierul de iesire
    fout << suma << endl;

    return 0;
}