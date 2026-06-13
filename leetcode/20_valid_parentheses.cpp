/*
20. Valid Parentheses
Solved in 16'28''
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
                left++;
            } else {
                if (stk.empty()) return false;
                switch (stk.top()) {
                    case '(':
                        if (s[i] == ')') {
                            stk.pop();
                            right++;
                            break;
                        } else {
                            return false;
                        }
                    case '{':
                        if (s[i] == '}') {
                            stk.pop();
                            right++;
                            break;
                        } else {
                            return false;
                        }
                    case '[':
                        if (s[i] == ']') {
                            stk.pop();
                            right++;
                            break;
                        } else {
                            return false;
                        }
                }
            }
        }
        if (left == right)
            return true;
        return false;
    }
};

// AI's cleaner answer:
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                char t = st.top();
                st.pop();

                if ((t == '(' && c != ')') ||
                    (t == '{' && c != '}') ||
                    (t == '[' && c != ']'))
                    return false;
            }
        }

        return st.empty();
    }
};
