#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2005;
long long sum_matrix[MAXN][MAXN];

inline int read() {
    int x = 0, f = 1;
    char ch = cin.get();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = cin.get();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = cin.get();
    }
    return x * f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    if (cin >> n >> m >> q) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                long long val = read();
                sum_matrix[i][j] = val + sum_matrix[i - 1][j] + sum_matrix[i][j - 1] - sum_matrix[i - 1][j - 1];
            }
        }

        while (q--) {
            int x1 = read();
            int y1 = read();
            int x2 = read();
            int y2 = read();

            long long ans = sum_matrix[x2][y2] - sum_matrix[x1 - 1][y2] - sum_matrix[x2][y1 - 1] + sum_matrix[x1 - 1][y1 - 1];
            cout << ans << "\n";
        }
    }
    return 0;
}
