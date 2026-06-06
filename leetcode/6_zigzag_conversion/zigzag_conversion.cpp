#include <vector>
#include <string>

class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<std::vector<char>> zigzag(numRows, std::vector<char>(s.length(), ' '));
        std::string result;

        if (numRows <= 1 || s.length() == 0) {
            return s;
        }

        for (int i = 0; i < s.length(); ++i) {
            int pattern = i % (2 * (numRows - 1));
            int col = i / (2 * (numRows - 1)) * (numRows - 1);

            if (pattern < numRows) {
                zigzag[pattern][col] = s[i];
            } else {
                int row = (2 * (numRows - 1)) - pattern;
                int inter_col = col + (pattern - numRows + 1);
                zigzag[row][inter_col] = s[i];
            }
        }

        for (int i = 0; i < zigzag.size(); ++i) {
            for (int j = 0; j < zigzag[0].size(); ++j) {
                if (zigzag[i][j] != ' ') {
                    result += zigzag[i][j];
                }
            }
        }

        return result;
    }
};
