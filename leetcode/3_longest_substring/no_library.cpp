#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const char* str = s.c_str();
        int seen[256] = {0};
        int maxLen = 0;
        int start = 0;

        for (int i = 0; str[i] != '\0'; ++i) {
            unsigned char c = str[i];

            if (seen[c] > 0) {
                while (str[start] != c) {
                    seen[(unsigned char)str[start]] = 0;
                    ++start;
                }
                ++start;
            }

            seen[c] = 1;
            int currentLen = i - start + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }

        return maxLen;
    }
};
