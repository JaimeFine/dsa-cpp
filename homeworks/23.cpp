#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (k >= n) {
            for (int i = 0; i < n; ++i) {
                cout << 0 << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        } else {
            for (int i = k; i < n; ++i) {
                cout << a[i] << " ";
            }
            for (int i = 0; i < k; ++i) {
                cout << 0 << (i == k - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    
    return 0;
}
