#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        vector<int> count(36, 0);

        for (char c : s) {
            if (isdigit(c)) {
                count[c - '0']++;
            } else if (isalpha(c)) {
                count[toupper(c) - 'A' + 10]++;
            }
        }

        int max_freq = 0;
        for (int i = 0; i < 36; ++i) {
            max_freq = max(max_freq, count[i]);
        }

        if (max_freq == 0) {
            cout << "0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n";
            continue;
        }

        for (int row = max_freq; row >= 1; --row) {
            for (int i = 0; i < 36; ++i) {
                if (count[i] >= row) {
                    cout << '*';
                } else {
                    cout << '-';
                }
                if (i < 35) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }

        for (int i = 0; i < 10; ++i) {
            cout << i << ' ';
        }
        for (int i = 0; i < 26; ++i) {
            cout << (char)('A' + i) << (i == 25 ? "" : " ");
        }
        cout << '\n';
    }

    return 0;
}
