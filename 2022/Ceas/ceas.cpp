#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int c, n, digit;
    int count = 0;

    // Read c, digit and n from "ceas.in"
    ifstream fin("ceas.in");

    // Write the result to "ceas.out"
    ofstream fout("ceas.out");

    fin >> c >> digit >> n;
    int numbers[n];

    if (c == 1) {
        // Take each number and count how many times x appears in it
        for (int i = 0; i < n; i++) {
            fin >> numbers[i];
            while (numbers[i] > 0) {
                if (numbers[i] % 10 == digit) {
                    count++;
                }
                numbers[i] /= 10;
            }
        }

        fout << count << endl;
    } else {
        // Due to an error the printer prints plates with natural numbers, some larger than 12. The workshop can only use plates with numbers between 0 and 12. In order to use these numbers, they need to be cut out from the right-hand side ı̂in groups of no more than two digits, each group representing the value on a plate, which is a digit from 0 to 9 or one of the numbers 10, 11, 12. If a number greater than 12 is found on a plate, then the plate must be cut out so that ı̂the cut-out results in numbers of no more than 2 digits. If ı̂in the number on a plate the digit of the tens is 0, then on the first cut only the digit of the units is taken, otherwise if the number formed by the digit of the tens and units is greater than 12, then the digit of the units is cut first, and if the number formed by the digit of the tens and units is 10, 11 or 12 the number formed by the last two digits is cut first, then the procedure is repeated until the plate is completely cut. The printer has made N plates. For example if the plate is 12030, after cutting 0, 3, 0, 12.
        for (int i = 0; i < n; i++) {
            fin >> numbers[i];
            while (numbers[i] > 0) {
                if ((numbers[i] / 10) % 10 == 0 && numbers[i] > 9) {
                    count += 2;
                    numbers[i] /= 100;
                } else if (numbers[i] % 100 <= 12) {
                    count++;
                    cout << numbers[i] % 100 << endl;
                    numbers[i] /= 100;
                } else {
                    count++;
                    cout << numbers[i] % 10 << endl;
                    numbers[i] /= 10;
                }
            }
        }
        fout << (count + 1) / 2 << endl;
    }
}