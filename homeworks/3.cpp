#include <iostream>
#include <cstdio>
#include <cmath>

void calculate() {
    double a, b, c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return;

    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    double r = area / p;

    printf("%.2f\n", r);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        calculate();
    }

    return 0;
}
