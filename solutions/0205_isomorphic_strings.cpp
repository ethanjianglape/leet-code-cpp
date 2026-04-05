// https://leetcode.com/problems/isomorphic-strings/description/
// Difficulty: Easy
//
// Given two strings s and t, determine if they are isomorphic.
//
// Two strings s and t are isomorphic if the characters in s can be replaced
// to get t.
//
// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character, but a character may map to itself.
//
// Example 1:
//   Input: s = "egg", t = "add"
//   Output: true
//   Explanation:
//   - Mapping 'e' to 'a'.
//   - Mapping 'g' to 'd'.
//
// Example 2:
//   Input: s = "f11", t = "b23"
//   Output: false
//   Explanation: '1' needs to be mapped to both '2' and '3'.
//
// Example 3:
//   Input: s = "paper", t = "title"
//   Output: true
//
// Constraints:
//   - 1 <= s.length <= 5 * 10^4
//   - t.length == s.length
//   - s and t consist of any valid ASCII character.

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        std::unordered_map<char, char> from{};
        std::unordered_map<char, char> to{};

        int n = s.length();

        for (int i = 0; i < n; i++) {
            char sc = s[i];
            char tc = t[i];

            if (!from.contains(sc)) {
                from[sc] = tc;
            }

            if (!to.contains(tc)) {
                to[tc] = sc;
            }

            if (!from.contains(sc)) {
                from[sc] = tc;
                to[tc] = sc;
            } else if (from[sc] != tc || to[tc] != sc) {
                return false;
            }
        }

        return true;
    }
};

int main() { return 0; }
