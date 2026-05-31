#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAXN = 1000005;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deque<int> dq;
    bool first = true;

    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            if (!first) {
                cout << " ";
            }
            cout << arr[dq.front()];
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
