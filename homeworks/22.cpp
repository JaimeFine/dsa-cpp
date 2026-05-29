#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, R;
    if (cin >> L >> R) {
        long long total_pairs = 0;

        for (int a = L; a <= R; ++a) {
            int temp = a;
            int power = 1;
            int digits = 0;
            while (temp >= 10) {
                power *= 10;
                temp /= 10;
                digits++;
            }
            digits++;

            int current = a;
            
            int found1 = 0, found2 = 0, found3 = 0, found4 = 0, found5 = 0, found6 = 0, found7 = 0;

            for (int i = 0; i < digits - 1; ++i) {
                int last_digit = current % 10;
                current = last_digit * power + (current / 10);

                if (current > a && current <= R) {
                    if (current == found1 || current == found2 || current == found3 || 
                        current == found4 || current == found5 || current == found6 || current == found7) {
                        continue; 
                    }
                    
                    if (found1 == 0) found1 = current;
                    else if (found2 == 0) found2 = current;
                    else if (found3 == 0) found3 = current;
                    else if (found4 == 0) found4 = current;
                    else if (found5 == 0) found5 = current;
                    else if (found6 == 0) found6 = current;
                    else if (found7 == 0) found7 = current;

                    total_pairs++;
                }
            }
        }

        cout << total_pairs << "\n";
    }

    return 0;
}
