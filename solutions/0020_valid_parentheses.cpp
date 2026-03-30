// https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
//
// Given a string s containing just the characters '(', ')', '{', '}', '['
// and ']', determine if the input string is valid.
//
// An input string is valid if:
//   1. Open brackets must be closed by the same type of brackets.
//   2. Open brackets must be closed in the correct order.
//   3. Every close bracket has a corresponding open bracket of the same type.
//
// Example 1:
//   Input:  s = "()"
//   Output: true
//
// Example 2:
//   Input:  s = "()[]{}"
//   Output: true
//
// Example 3:
//   Input:  s = "(]"
//   Output: false
//
// Example 4:
//   Input:  s = "([])"
//   Output: true
//
// Example 5:
//   Input:  s = "([)]"
//   Output: false
//
// Constraints:
//   1 <= s.length <= 10^4
//   s consists of parentheses only: '()[]{}'

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;

        std::stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c =='{') {
                stack.push(c);
                continue;
            }

            if (stack.empty()) return false;

            char top = stack.top();

            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
            if (c == '}' && top != '{') return false;

            stack.pop();
        }

        return stack.empty();
    }
};

int main() { return 0; }
