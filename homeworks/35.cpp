#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string c, x, y;
    while (getline(cin, c)) {
        if (!getline(cin, x)) break;
        if (!getline(cin, y)) break;

        string result = "";
        size_t pos = 0;
        size_t found_pos;

        while ((found_pos = c.find(x, pos)) != string::npos) {
            result += c.substr(pos, found_pos - pos);

            result += y;

            pos = found_pos + x.length();
        }

        result += c.substr(pos);

        cout << result << "\n";
    }

    return 0;
}
