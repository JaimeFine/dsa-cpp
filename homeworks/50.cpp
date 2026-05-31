#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }

    vector<long long> inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }

    long long current_coef = 1;
    cout << current_coef;

    for (int k = 1; k <= n; ++k) {
        current_coef = current_coef * (n - k + 1) % MOD;
        current_coef = current_coef * inv[k] % MOD;
        cout << " " << current_coef;
    }
    cout << "\n";

    return 0;
}
