#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if (ch == ')' && top != '(') return false;
            if (ch == ']' && top != '[') return false;
            if (ch == '}' && top != '{') return false;
            if (ch == '>' && top != '<') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    for (int i = 0; i < 3; ++i) {
        if (cin >> s) {
            if (isValid(s)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
