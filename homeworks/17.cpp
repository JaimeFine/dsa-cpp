#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x = 0;

    for (int i = 0; i < 32; ++i) {
        long long a;
        cin >> a;

        if (a == 1) {
            x += (1LL << i);
        }
    }

    cout << x << "\n";

    return 0;
}
