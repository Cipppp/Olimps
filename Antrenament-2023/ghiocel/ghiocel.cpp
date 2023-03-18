#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("ghiocel.in");
    ofstream fout("ghiocel.out");

    int c, n;
    fin >> c >> n;

    // Citim numerele din fisier
    int aspectDeUrcus = 0, aspectDeCoboras = 0, aspectDeDeal = 0, aspectDeVale = 0;
    for (int i = 0; i < n; i++) {
        int b;
        fin >> b;

        int cifre[10] = {0};
        int lungime = 0;
        // Descompunem numarul in cifre
        while (b) {
            cifre[lungime++] = b % 10;
            b /= 10;
        }

        bool creste = true, scade = true;
        // Verificam daca cifrele sunt in ordine crescatoare sau descrescatoare
        for (int j = 1; j < lungime; j++) {
            // Daca cifrele nu sunt in ordine descrescatoare, nu mai are rost sa verificam daca sunt in ordine crescatoare
            if (cifre[j] >= cifre[j - 1]) {
                creste = false;
            }
            // Daca cifrele nu sunt in ordine crescatoare, nu mai are rost sa verificam daca sunt in ordine descrescatoare
            if (cifre[j] <= cifre[j - 1]) {
                scade = false;
            }
        }

        if (creste) {
            aspectDeUrcus++;
        } else if (scade) {
            aspectDeCoboras++;
        } else if (cifre[0] < cifre[1]) {
            // Verificam daca cifrele sunt in ordine crescatoare
            for (int j = 2; j < lungime; j++) {
                if (cifre[j] >= cifre[j - 1]) {
                    break;
                }
                if (j == lungime - 1) {
                    aspectDeDeal++;
                }
            }
        } else {
            // Verificam daca cifrele sunt in ordine descrescatoare
            for (int j = 2; j < lungime; j++) {
                if (cifre[j] <= cifre[j - 1]) {
                    break;
                }
                if (j == lungime - 1) {
                    aspectDeVale++;
                }
            }
        }
    }

    // Scriem raspunsul in fisierul de iesire
    if (c == 1) {
        fout << aspectDeUrcus << "\n";
    } else if (c == 2) {
        fout << aspectDeCoboras << "\n";
    } else if (c == 3) {
        fout << aspectDeDeal << "\n";
    } else {
        fout << aspectDeVale << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}