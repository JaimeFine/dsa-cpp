#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
int parent_arr[MAXN];

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

int find_set(int i) {
    if (parent_arr[i] == i)
        return i;
    return parent_arr[i] = find_set(parent_arr[i]);
}

void union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent_arr[root_i] = root_j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, n;
    if (cin >> q >> n) {
        for (int i = 1; i <= n; ++i) {
            parent_arr[i] = i;
        }

        while (q--) {
            int op = read();
            int x = read();
            int y = read();

            if (op == 1) {
                union_sets(x, y);
            } else if (op == 2) {
                if (find_set(x) == find_set(y)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
