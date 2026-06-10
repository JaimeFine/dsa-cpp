/*
17. Letter Combinations of a Phone Number
Solved in 35'54''
Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    vector<string> output;
    unordered_map<char, string> mp = {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
        {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
        {'8',"tuv"}, {'9',"wxyz"}
    };
    void dfs(
        string& digits, int idx, string& temp
    ) {
        if (idx == digits.size()) {
            output.push_back(temp);
            return;
        }
        string letters = mp[digits[idx]];
        for (char c : letters) {
            temp.push_back(c);
            dfs(digits, idx+1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        dfs(digits, 0, temp);
        return output;
    }
};