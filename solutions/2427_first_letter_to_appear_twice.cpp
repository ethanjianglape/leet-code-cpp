// https://leetcode.com/problems/first-letter-to-appear-twice/
// Difficulty: Easy
//
// Given a string `s` consisting of lowercase English letters, return the first
// letter to appear twice.
//
// A letter `a` appears twice before another letter `b` if the second occurrence
// of `a` comes before the second occurrence of `b`.
// The string `s` is guaranteed to have at least one repeated letter.
//
// Example 1:
//   Input:  s = "abccbaacz"
//   Output: 'c'
//   Explanation: 'c' appears at indices 2, 3, and 7. Its second occurrence
//   (index 3) comes before 'a's second (index 5) and 'b's second (index 4).
//
// Example 2:
//   Input:  s = "abcdd"
//   Output: 'd'
//   Explanation: 'd' is the only repeated character.
//
// Constraints:
//   2 <= s.length <= 100
//   s consists of lowercase English letters
//   At least one letter appears twice

#include <string>
#include <unordered_set>

class Solution {
public:
    char repeatedCharacter(std::string s) {
        std::unordered_set<char> seen{};

        for (char c : s) {
            if (seen.contains(c)) {
                return c;
            }

            seen.insert(c);
        }

        return '\0';
    }
};

int main() { return 0; }
