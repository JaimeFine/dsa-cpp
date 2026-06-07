/*
14. Longest Common Prefix
Solved in 42'07''
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = strs[0];
        string buffer = "";
        for (int i = 1; i < strs.size(); i++) {
            int min = std::min(strs[0].length(), strs[i].length());
            for (int k = 0; k < min; k++) {
                if (strs[0][k] == strs[i][k]) {
                    buffer += strs[0][k];
                } else {
                    break;
                }
            }
            if (buffer.size() < output.size())
                output = buffer;
            buffer.clear();
            if (output == "")
                break;
        }
        return output;
    }
};

// Better Answer:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};