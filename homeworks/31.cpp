#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int charToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

char valueToChar(int v) {
    if (v >= 0 && v <= 9) {
        return v + '0';
    }
    return v - 10 + 'A';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    while (cin >> k) {
        string x;
        int q;
        cin >> x >> q;

        long long num10 = 0;
        for (char c : x) {
            num10 = num10 * k + charToValue(c);
        }

        if (num10 == 0) {
            cout << "0\n";
            continue;
        }

        string result = "";
        while (num10 > 0) {
            int remainder = num10 % q;
            result += valueToChar(remainder);
            num10 /= q;
        }

        reverse(result.begin(), result.end());

        cout << result << "\n";
    }

    return 0;
}
