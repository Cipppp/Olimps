#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

// Verificam daca un numar este prim
bool is_prime(int dimensiune) {
    if (dimensiune <= 1) return false;
    for (int i = 2; i <= dimensiune; i++) {
        if (dimensiune % i == 0) return false;
    }
    return true;
}

// Calculam suma cifrelor unui numar
int digit_sum(int dimensiune) {
    int sum = 0;
    while (dimensiune > 0) {
        sum += dimensiune % 10;
        dimensiune /= 10;
    }
    return sum;
}

int main() {
    ifstream input("aeriana.in");  // ifstream fin("aeriana.in");
    ofstream ouput("aeriana.out");

    int c, dimensiune;
    int a1, a2, h1, m1, h2, m2;
    int max_duration_before = 0, max_duration_after = 0;
    input >> c >> dimensiune;

    if (c == 1) {
        for (int i = 0; i < dimensiune; i++) {
            input >> a1 >> a2 >> h1 >> m1 >> h2 >> m2;

            // Din momentul sosirii scadem ora de plecare si minutul de plecare
            int duration_before = (h2 - h1) * 60 + (m2 - m1);  // Pastram durata in minute

            // Daca durata este mai mare decat cea maxima, o actualizam
            if (duration_before > max_duration_before) {
                max_duration_before = duration_before;
            }
        }

        ouput << max_duration_before / 60 << " " << max_duration_before % 60 << endl;
    } else if (c == 2) {
        // check if flight is special and reverse times
        if (is_prime(a1) && a2 % digit_sum(a1) == 0) {
            swap(h1, h2);
            swap(m1, m2);
        }

        // calculate duration after virus intervention
        int duration_after = (h2 - h1) * 60 + (m2 - m1) % 60;
        if (duration_after > max_duration_after) {
            max_duration_after = duration_after;
        }
        ouput << max_duration_after / 60 << " " << max_duration_after % 60 << endl;
    }

    input.close();
    ouput.close();

    return 0;
}
