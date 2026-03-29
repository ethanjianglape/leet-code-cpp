// URL: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
// Difficulty: Easy
//
// Problem:
// You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
//
// You can apply the following operation on either of the two strings any number of times:
//   - Choose any two indices i and j such that j - i = 2, then swap the two characters at those
//     indices in the string.
//
// Return true if you can make the strings s1 and s2 equal, and false otherwise.
//
// Example 1:
//   Input:  s1 = "abcd", s2 = "cdab"
//   Output: true
//   Explanation: Apply to s1:
//     Swap indices i=0, j=2 → s1 = "cbad"
//     Swap indices i=1, j=3 → s1 = "cdab" which equals s2
//
// Example 2:
//   Input:  s1 = "abcd", s2 = "dacb"
//   Output: false
//   Explanation: It is not possible to make the two strings equal.
//
// Constraints:
//   - s1.length == s2.length == 4
//   - s1 and s2 consist only of lowercase English letters.

#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }

        std::string s1Evens;
        std::string s1Odds;
        std::string s2Evens;
        std::string s2Odds;

        s1Evens.reserve(s1.size() / 2);
        s1Odds.reserve(s1.size() / 2);
        s2Evens.reserve(s2.size() / 2);
        s2Odds.reserve(s2.size() / 2);

        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                s1Evens.push_back(s1[i]);
            } else {
                s1Odds.push_back(s1[i]);
            }
        }

        for (int i = 0; i < s2.length(); i++) {
            if (i % 2 == 0) {
                s2Evens.push_back(s2[i]);
            } else {
                s2Odds.push_back(s2[i]);
            }
        }

        std::ranges::sort(s1Evens);
        std::ranges::sort(s1Odds);
        std::ranges::sort(s2Evens);
        std::ranges::sort(s2Odds);

        return s1Evens == s2Evens && s1Odds == s2Odds;
    }
};

int main(int argc, char** argv) {
    return 0;
}
