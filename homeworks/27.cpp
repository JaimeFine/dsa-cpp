#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y) {
        int count = 0;

        for (int i = x; i <= y; ++i) {
            if (i == 0) continue;

            for (int j = x; j <= y; ++j) {
                if (j == i) continue;

                for (int k = x; k <= y; ++k) {
                    if (k == i || k == j) continue;

                    for (int l = x; l <= y; ++l) {
                        if (l == i || l == j || l == k) continue;

                        count++;
                    }
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
