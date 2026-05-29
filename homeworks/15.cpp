#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double x;
    if (cin >> x) {
        double fl = floor(x);
        long long fl_int = static_cast<long long>(fl);

        double result;

        if (fl_int % 2 == 0) {
            result = x - fl;
        } else {
            result = fl - x + 1;
        }

        printf("%.2f\n", result);
    }
    return 0;
}
