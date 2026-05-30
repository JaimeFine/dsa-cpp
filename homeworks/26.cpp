#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n) {
        long long sum = 0;
        int val;
        
        for (int i = 0; i < n; ++i) {
            cin >> val;
            sum += val;
        }

        double average = (double)sum / n;

        cout << fixed << setprecision(2) << average << "\n";
    }

    return 0;
}
