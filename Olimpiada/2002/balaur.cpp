#include <iostream>

using namespace std;

int main() {
    int n;  // number of days
    cin >> n;

    int heads = 6;  // initial number of heads

    cout << (n - 1) * 6 + (heads - n) << endl;
    return 0;
}
