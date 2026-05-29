#include <iostream>

using namespace std;

int main() {
    int a, b;
    if (cin >> a >> b) {
        if (a == b) {
            cout << a << "\n";
        } else {
            cout << (3 - a - b) << "\n";
        }
    }

    return 0;
}
