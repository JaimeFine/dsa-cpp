#include <iostream>
#include <vector>

int main() {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> array(n, std::vector<int>(4));

        for (int i = 0; i < n; i++) {
                int x, t, v, T;
                std::cin >> x >> t >> v >> T;

                array[i] = {x, t, v, T};
        }

        for (int i = 0; i < n; i++) {
                int x, t, v, T, fuck;
                x = array[i][0];
                t = array[i][1];
                v = array[i][2];
                T = array[i][3];

                fuck = t + (x + v - 1) / v;
                if(fuck > T)
                        std::cout << "NO!!!" << std::endl;
                else
                        std::cout << "Nice!" << std::endl;

        }

        return 0;
}
