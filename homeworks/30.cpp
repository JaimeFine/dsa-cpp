#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y) {

        while (y != 0) {
            int remainder = x % y;
            x = y;
            y = remainder;
        }

        cout << x << "\n";
    }

    return 0;
}
