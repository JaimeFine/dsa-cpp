#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n) {
        long long sum = 0;

        for (long long i = 1; i <= n; ++i) {
            sum += i * i;
        }

        cout << sum << "\n";
    }

    return 0;
}
