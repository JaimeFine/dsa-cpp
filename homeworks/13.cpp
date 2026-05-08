#include <iostream>
using namespace std;

int main() {
    int n, x, y, l, r;
    cin >> n >> x >> y >> l >> r;
    
    long long emyin_sum = 0;
    long long step_sum = 0;
    
    for (int i = l; i <= r; i++) {
        if (i % x == 0 && i % y == 0) {
            emyin_sum += i;
        }
        
        if (i % x == 0 || i % y == 0) {
            step_sum += i;
        }
    }
    
    cout << emyin_sum << " " << step_sum << endl;
    
    return 0;
}