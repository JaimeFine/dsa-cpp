#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        int chicken = -1;
        int rabbit = -1;

        for (int i = 0; i <= n; ++i) {
            int j = n - i;

            if (2 * i + 4 * j == m) {
                chicken = i;
                rabbit = j;
                break;
            }
        }

        cout << chicken << " " << rabbit << "\n";
    }

    return 0;
}
