#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    long long w;
    if (scanf("%d %lld", &n, &w) != 2) return 0;

    for (int i = 0; i < n; ++i) {
        long long v, s;
        scanf("%lld %lld", &v, &s);

        if (v <= w * s) {
            printf("Yes\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
