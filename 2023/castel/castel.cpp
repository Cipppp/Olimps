#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream input("castel.in");
    ofstream ouput("castel.out");

    int tipulCerintei, dimensiune;
    input >> tipulCerintei >> dimensiune;

    // Citim numerele din fisier
    int listaNumere[dimensiune];
    for (int i = 0; i < dimensiune; i++) {
        input >> listaNumere[i];
    }

    if (tipulCerintei == 1) {
        int contorCuburi = 0;
        for (int i = 0; i < dimensiune; i++) {
            if (listaNumere[i] < 10) {
                contorCuburi++;
            }
        }
        ouput << contorCuburi << endl;
    }

    // Requirement 2 and 3
    int max_rows = 1, top_value = listaNumere[dimensiune];
    int cnt_blue_cubes = 0, sum_blue_cubes = 0;
    for (int i = dimensiune + 1; i < 2 * dimensiune; i++) {
        int j = i;
        int row = 2;
        int row_value = listaNumere[i];

        while (j > row) {
            row++;
            row_value = listaNumere[j] + listaNumere[j - 1];
            j = j - 2;
        }

        if (row > max_rows) {
            max_rows = row;
            top_value = row_value;
        }

        if (i % 2 == 0) {  // if blue cube
            cnt_blue_cubes++;
            sum_blue_cubes += row_value;
        }
    }

    ouput << max_rows << " " << top_value << endl;
    ouput << cnt_blue_cubes << " " << sum_blue_cubes << endl;

    input.close();
    ouput.close();
    return 0;
}
