#include <iostream>

using namespace std;

void printRow(int i, int n, int t) {
    for (int j = 1; j <= n; ++j) {
        if (j % t == 0) {
            cout << '*';
        } else {
            cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        printRow(i, n, t);
    }

    return 0;
}
