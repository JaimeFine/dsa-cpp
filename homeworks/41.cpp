#include <iostream>

using namespace std;

const int MAXN = 200005;
int push_seq[MAXN];
int pop_seq[MAXN];
int st[MAXN];

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

void solve() {
    int n;
    cin >> n;
    if (!cin) return;

    for (int i = 0; i < n; ++i) push_seq[i] = read();
    for (int i = 0; i < n; ++i) pop_seq[i] = read();

    int top = 0;
    int pop_idx = 0;

    for (int i = 0; i < n; ++i) {
        st[top++] = push_seq[i];

        while (top > 0 && st[top - 1] == pop_seq[pop_idx]) {
            top--;
            pop_idx++;
        }
    }

    if (pop_idx == n && top == 0) {
        cout << "YES\n";
    } else {
        cout << "N0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}