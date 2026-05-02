#include <iostream>
#include <cstdio>
#include <numeric>

long long get_gcd(long long a, long long b) {
    return b == 0 ? a : get_gcd(b, a % b);
}

void solve() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return;

    if (m % n != 0) return;

    int k = m / n;
    for (int x = 1; x * x <= k; ++x) {
        if (k % x == 0) {
            int y = k / x;
            if (get_gcd(x, y) == 1) {
                printf("%d %d\n", n * x, n * y);
            }
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
