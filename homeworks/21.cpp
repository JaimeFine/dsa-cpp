#include <iostream>

using namespace std;

int main() {
    int n;
    if (cin >> n) {
        if (n == 1 || n == 2) {
            cout << 1 << "\n";
            return 0;
        }

        long long a = 1;
        long long b = 1;
        long long c = 0;

        for (int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        cout << c << "\n";
    }

    return 0;
}
