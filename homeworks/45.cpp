#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, x, y;
    if (!(cin >> n >> m >> x >> y)) return 0;

    long long MOD = 998244353;
    long long ans = 1;

    long long forbidden = 0;
    if (x - 1 >= 1) forbidden++;
    if (x >= 1 && x <= n) forbidden++;
    if (x + 1 <= n) forbidden++;
    long long choices_neighbor = max(0LL, n - forbidden);

    for (int j = 1; j <= m; ++j) {
        long long choices = 0;
        if (j == y) {
            choices = 1;
        } else if (j == y - 1 || j == y + 1) {
            choices = choices_neighbor;
        } else {
            choices = max(0LL, n - 1);
        }
        ans = (ans * choices) % MOD;
    }

    cout << ans << "\n";

    return 0;
}
