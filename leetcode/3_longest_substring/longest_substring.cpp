#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int longest = 0;
        std::unordered_map<char, int> seen;

        for (int i = 0; i < s.size(); i++) {
                if (seen.count(s[i]) && seen[s[i]] >= start) {
                    start = seen[s[i]] + 1;
                }
            seen[s[i]] = i;
            longest = std::max(longest, i - start + 1);
        }

        return longest;
    }
};

