#include <iostream>
#include <fstream>
#include <numeric>
#include <cmath>
#include <conio.h>

using namespace std;

int digitsOfNumber(int x) {
    x = abs(x);
    int n = 1;
    while ((x /= 10) > 0)
        n++;
    return n;
}

int getNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (gcd(n, i) == 1)
            sum++;
    return sum;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    //int numbers = getNumber(n);
    for (int k = 1; k <= n; k++) {
        if (gcd(k, n) == 1) {
            int spaces = digitsOfNumber(k) + 1;
            int sum = 1;
            int rev = 1;
            cout << k << ": ";
            int buff = k;
            cout << buff << " ";
            if ((buff * k % n) == 1) {
                rev = buff;
            }
            while (buff != 1) {
                sum++;
                buff *= k;
                if (buff > n) {
                    buff %= n;
                }
                if ((buff * k % n) == 1) {
                    rev = buff;
                }
                spaces += digitsOfNumber(buff) + 1;
                cout << (buff % n) << " ";
            }
            for (int i = spaces; i < n * 2; i++) {
                cout << " ";
            }
            cout << "|x| = " << sum << ", x^-1 = " << rev  << endl;
        }
    }
    _getch();
}
