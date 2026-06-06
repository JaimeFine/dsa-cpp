#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::vector<std::vector<bool>> vec(s.length() + 1, std::vector<bool>(p.length() + 1, false));

        vec[0][0] = true;

        for (int j = 1; j < p.length(); ++j) {
            if (p[j - 1] == '*') {
                vec[0][j] = vec[0][j - 2];
            }
        }

        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    vec[i][j] = vec[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    char pre_char = p[j - 2];

                    vec[i][j] = vec[i][j - 2];
                    if (pre_char == s[i - 1] || pre_char == '.') {
                        vec[i][j] = vec[i][j] || vec[i - 1][j];
                    }
                }
            }
        }

        return vec[s.length()][p.length()];
    }
};