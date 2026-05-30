#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c;
    while (cin >> n >> a >> b >> c) {
        int max_eat = -1;
        int min_range = 1e9;

        for (int i = 1; i * a <= n; ++i) {
            for (int j = 1; i * a + j * b <= n; ++j) {
                for (int k = 1; i * a + j * b + k * c <= n; ++k) {
                    int current_sum = i * a + j * b + k * c;

                    int v1 = i * a;
                    int v2 = j * b;
                    int v3 = k * c;

                    int current_max = max({v1, v2, v3});
                    int current_min = min({v1, v2, v3});
                    int current_range = current_max - current_min;

                    if (current_sum > max_eat) {
                        max_eat = current_sum;
                        min_range = current_range;
                    }
                    else if (current_sum == max_eat) {
                        if (current_range < min_range) {
                            min_range = current_range;
                        }
                    }
                }
            }
        }

        if (max_eat == -1) {
            cout << "-1 -1\n";
        } else {
            cout << max_eat << " " << min_range << "\n";
        }
    }

    return 0;
}
