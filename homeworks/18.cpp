#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, s, p;
    if (cin >> t >> s >> p) {
        int min_val = min({t, s, p});
        int max_val = max({t, s, p});

        int mid_val = (t + s + p) - min_val - max_val;

        if (mid_val - min_val == max_val - mid_val) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
