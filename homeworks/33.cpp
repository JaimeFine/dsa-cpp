#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, k;
    while (cin >> n >> m >> q >> k) {
        vector<bool> row_line(n + 1, false);
        vector<bool> col_line(m + 1, false);

        for (int i = 0; i < q; ++i) {
            int r;
            cin >> r;
            row_line[r] = true;
        }

        for (int i = 0; i < k; ++i) {
            int c;
            cin >> c;
            col_line[c] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (row_line[i] && col_line[j]) {
                    cout << '+';
                } else if (row_line[i]) {
                    cout << '-';
                } else if (col_line[j]) {
                    cout << '|';
                } else {
                    cout << '0';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
