#include <iostream>
using namespace std;
int main() {
    int x, sum, cifra_zeci, cifra_unitati;

    cin >> x;

    cifra_unitati = x % 10;
    cifra_zeci = x / 10;
    sum = cifra_unitati + cifra_zeci;
    cout << sum;

    // 68254 / 100
    // 1. /
    // 2. %
}