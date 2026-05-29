#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b;
    if (cin >> n >> a >> b) {
        long long row_a = (a - 1) / n;
        long long col_a = (a - 1) % n;

        long long row_b = (b - 1) / n;
        long long col_b = (b - 1) % n;

        bool is_horizontal = (row_a == row_b) && (abs(col_a - col_b) == 1);
        bool is_vertical = (col_a == col_b) && (abs(row_a - row_b) == 1);

        if (is_horizontal || is_vertical) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
