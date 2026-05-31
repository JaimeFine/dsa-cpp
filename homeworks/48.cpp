#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int pos[MAXN];
int l, n, k;

bool check(int mid) {
    long long required_k = 0;
    for (int i = 1; i < n; ++i) {
        int dist = pos[i] - pos[i - 1];
        if (dist > mid) {
            required_k += (dist - 1) / mid;
        }
    }
    return required_k <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> l >> n >> k)) return 0;

    int max_dist = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
        if (i > 0) {
            max_dist = max(max_dist, pos[i] - pos[i - 1]);
        }
    }

    int left = 1;
    int right = max_dist;
    int ans = max_dist;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
