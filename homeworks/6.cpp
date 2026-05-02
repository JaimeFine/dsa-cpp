#include <iostream>
#include <string>

using namespace std;

int main() {
    int num = 0;

    cin >> num;
    for (int t = 0; t < num; ++t) {
        string s;
        cin >> s;
        
        int diff = 0;
        string target = "abc";

        for (int i = 0; i < 3; ++i) {
            if (s[i] != target[i]) {
                diff++;
            }
        }

        if (diff == 3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
