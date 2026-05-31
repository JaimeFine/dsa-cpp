#include <iostream>

using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    long long low = 1;
    long long high = 1000000; 
    long long ans = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        long long mid_ll = mid;
        long long current_val = 6 * mid_ll * mid_ll * mid_ll + 2 * mid_ll * mid_ll - mid_ll;

        if (current_val == n) {
            ans = mid;
            break;
        } else if (current_val < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
