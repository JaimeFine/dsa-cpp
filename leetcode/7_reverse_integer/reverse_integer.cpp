#include <vector>

class Solution {
public:
    int reverse(int x) {
        std::vector<int> num;
        bool sign = false;
        int result = 0;

        long long y = static_cast<long long>(x);

        if (y < 0) {
            y *= -1;
            sign = true;
        }

        while (y > 0) {
            num.push_back(y % 10);
            y /= 10;
        }

        for (int i = 0; i < num.size(); ++i) {
            if (result > (INT_MAX - num[i]) / 10)
                return result = 0;
            result = result * 10 + num[i];
        }

        if (sign == true)
            result *= -1;

        return result;
    }
};
