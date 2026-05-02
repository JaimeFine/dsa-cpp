#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> evens, odds;
        for (int x : a) {
            if (x % 2 == 0) {
                evens.push_back(x);
            } else {
                odds.push_back(x);
            }
        }

        sort(evens.rbegin(), evens.rend());
        sort(odds.begin(), odds.end());

        vector<int> optimal_sequence;
        for (int x : evens) optimal_sequence.push_back(x);
        for (int x : odds) optimal_sequence.push_back(x);

        long long ali_sum = 0, axin_sum = 0;
        bool valid = true;

        for (int candy : optimal_sequence) {
            if (candy % 2 == 0) {
                ali_sum += candy;
            } else {
                axin_sum += candy;
            }
            
            if (ali_sum <= axin_sum) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
