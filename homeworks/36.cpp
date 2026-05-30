#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> people(n);
        for (int i = 0; i < n; ++i) {
            people[i] = i + 1;
        }

        int current_pos = 0;

        for (int i = 0; i < n; ++i) {
            int step = a[i];
            int size = people.size();

            int target_idx = (current_pos + step - 1) % size;

            cout << people[target_idx] << (i == n - 1 ? "" : " ");

            people.erase(people.begin() + target_idx);

            current_pos = target_idx;
        }
        cout << "\n";
    }

    return 0;
}
