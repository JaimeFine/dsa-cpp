#include <iostream>

using namespace std;

int main() {
    long long n, m;
    if (cin >> n >> m) {
        if (m >= n && m <= 6 * n) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
