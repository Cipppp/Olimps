#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int cerinta, dim, primulNumar, sum = 0, max = 0, contor = 0, ultimaCifra, limita;

    // Citim numerele din fisier
    ifstream input("sss.in");

    // Citim tipul cerintei si numarul de elemente
    input >> cerinta >> dim;

    // Declaram un vector de elemente
    int numere[dim];

    // Deschidem un fisier
    ofstream output("sss.out");  // <--- deschidere fisier

    // Adaugare elemente in vector
    for (int index = 0; index < dim; index++)
        input >> numere[index];

    // % <-- mod
    // / <-- div

    // Verificam tipul cerintei
    if (cerinta == 1) {
        primulNumar = numere[0];

        // Cat timp ultima cifra e nula
        while (primulNumar % 10 == 0) {
            primulNumar = primulNumar / 10;
        }

        ultimaCifra = primulNumar % 10;

        for (int index = dim - ultimaCifra; index < dim; index++)
            sum += numere[index];

        output << sum;
    } else {
        // Daca avem un element afisam suma acestuia (singura secventa)
        if (dim == 1) {
            output << numere[0];
            return 0;
        } else {
            int pivot = 0;
            // Cat timp avem secvente in vector
            limita = (dim - 1) / 2 + 1;  // daca dim = 10 -> limita = 5

            // Cat timp limita nu depaseste numarul de elemente si limita nu este mai mica decat 0
            while (limita < dim && limita > 0) {
                int sumaSecventa = 0;

                // Calculam suma pentru secvente
                for (int index = pivot; index < limita; index++) {
                    sumaSecventa += numere[index];
                }

                // Verificam daca am gasit o suma mai mare decat suma anterioara si o actualizam
                if (sumaSecventa > max) {
                    max = sumaSecventa;
                }

                // Modificam inceputul secventei urmatoare
                pivot = limita;  // Inceputul secventei urmatoare este finalul primei secvente
                contor++;
                limita = limita + ((dim - 1) / 2 - contor);  // Urmatoare secventa (secventa 2) merge de la 5 --> 8
            }
        }

        output << max;
    }
}
