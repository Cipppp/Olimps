// Not my first C++ Program
#include <iostream>
#include <string>
using namespace std;
int main() {

    // string weekday = "vineri";
    
    // if (weekday == "duminica" || weekday == "sambata") {
    //     cout << "Sunt fericit, e weekend!";
    // } else {
    //     cout << "Sunt trist, avem scoala!";
    // }

// ==================
    // int a, b;

    // cin >> a;
    // cin >> b;

    // if (a == 0) {
    //     if (b == 0) {
    //         cout << "x oricare";
    //     } else {
    //         cout << "x nu exista";
    //     }
    // } else {
    //     int x = -b / a;
    //     cout << x;
    // }

    // ==================

    int n;
    int sum;

    cin >> n;

    sum = (n * (n + 1)) / 2;

    cout << sum;

    return 0;
}
    