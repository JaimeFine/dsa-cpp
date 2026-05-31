#include <iostream>
#include <deque>

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = cin.get();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = cin.get();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = cin.get();
    }
    return x * f;
}

int main() {
    int q;
    if (cin >> q) {
        deque<int> dq;
        
        while (q--) {
            int op = read();
            
            if (op == 1) {
                int x = read();
                dq.push_back(x);
            } else if (op == 2) {
                int x = read();
                dq.push_front(x);
            } else if (op == 3) {
                if (!dq.empty()) {
                    dq.pop_front();
                }
            } else if (op == 4) {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else if (op == 5) {
                if (!dq.empty()) {
                    cout << dq.front() << "\n";
                }
            }
        }
    }
    return 0;
}
