/*
22. Generate Parentheses
Solved in 1h16min30s
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string current = "";
        int i = 0, j = 0;
        DFS(output, current, n, i, j);
        return output;
    }

    void DFS(vector<string> &output, string current, int n, int i, int j) {
        if (current.size() == 2 * n) {
            output.push_back(current);
            return;
        }
        
        if (i < n) {
            DFS(output, current + '(', n, i+1, j);
        }
        
        if (i > j) {
            DFS(output, current + ')', n, i, j+1);
        }
    }
};
