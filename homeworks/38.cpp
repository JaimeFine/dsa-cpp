#include <iostream>
#include <vector>

using namespace std;

const int OFFSET = 10000;
int counts[20005] = {0};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        counts[num + OFFSET]++;
    }

    bool first = true;
    for (int i = 0; i <= 20000; ++i) {
        while (counts[i] > 0) {
            if (!first) {
                cout << " ";
            }
            cout << i - OFFSET;
            first = false;
            counts[i]--;
        }
    }
    cout << "\n";

    return 0;
}
