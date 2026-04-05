// https://leetcode.com/problems/word-pattern/description/
// Difficulty: Easy
//
// Given a pattern and a string s, find if s follows the same pattern.
//
// Here "follow" means a full match, such that there is a bijection between a
// letter in pattern and a non-empty word in s. Specifically:
//   - Each letter in pattern maps to exactly one unique word in s.
//   - Each unique word in s maps to exactly one letter in pattern.
//   - No two letters map to the same word, and no two words map to the same letter.
//
// Example 1:
//   Input: pattern = "abba", s = "dog cat cat dog"
//   Output: true
//   Explanation:
//   - 'a' maps to "dog".
//   - 'b' maps to "cat".
//
// Example 2:
//   Input: pattern = "abba", s = "dog cat cat fish"
//   Output: false
//
// Example 3:
//   Input: pattern = "aaaa", s = "dog cat cat dog"
//   Output: false
//
// Constraints:
//   - 1 <= pattern.length <= 300
//   - pattern contains only lower-case English letters.
//   - 1 <= s.length <= 3000
//   - s contains only lowercase English letters and spaces ' '.
//   - s does not contain any leading or trailing spaces.
//   - All the words in s are separated by a single space.

#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        auto words = ranges::to<vector<string>>(views::split(s, ' '));

        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> from{};
        unordered_map<string, char> to{};

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string word = words[i];

            if (!from.contains(c)) {
                from[c] = word;
            }

            if (!to.contains(word)) {
                to[word] = c;
            }

            if (from[c] != word || to[word] != c) {
                return false;
            }
        }

        return true;
    }
};

int main() { return 0; }
