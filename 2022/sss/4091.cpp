#include <unistd.h>

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int c, n, k, linit = 0, limit, s = 0, max = 0, iteration = 0;

    // Read the numbers from the sss.in file
    ifstream f("sss.in");
    f >> c >> n;
    int v[n];

    // Display the numbers in the sss.out file
    ofstream g("sss.out");

    for (int i = 0; i < n; i++)
        f >> v[i];
    if (c == 1) {
        k = v[0];

        while (k % 10 == 0) {
            k /= 10;
        }

        k = k % 10;

        for (int i = n - k; i < n; i++)
            s += v[i];
        g << s;
    } else {
        int index = linit;
        if (n == 1) {
            g << v[0];
            return 0;
        } else {
            limit = (n - 1) / 2 + 1;

            while (limit < n && limit > 0) {
                int sum = 0;
                for (int i = index; i < limit; i++)
                    sum += v[i];

                if (sum > max)
                    max = sum;

                index = limit;
                iteration++;
                limit = limit + ((n - 1) / 2 - iteration);
            }
        }

        g << max;
    }

    return 0;
}