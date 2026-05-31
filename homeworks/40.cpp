#include <iostream>
#include <vector>

using namespace std;

const int DAYS[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long convert(int month, int day, int hour, int minute) {
    long long total_min = 0;

    for (int m = 1; m < month; ++m) {
        total_min += (long long)DAYS[m] * 24 * 60;
    }

    total_min += (long long)(day - 1) * 24 * 60;
    total_min += (long long)hour * 60;
    total_min += minute;

    return total_min;
}

int main() {
    int m1, d1, h1, min1;
    int m2, d2, h2, min2;

    if (cin >> m1 >> d1 >> h1 >> min1 >> m2 >> d2 >> h2 >> min2) {
        long long start_total = convert(m1, d1, h1, min1);
        long long end_total = convert(m2, d2, h2, min2);

        long long diff = end_total - start_total;
        cout << diff << "\n";
    }

    return 0;
}