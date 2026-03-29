// URL: https://leetcode.com/problems/sort-characters-by-frequency/description/
// Difficulty: Medium
//
// ============================================================
// 451. Sort Characters By Frequency
// ============================================================
//
// Given a string s, sort it in decreasing order based on the frequency of the
// characters. The frequency of a character is the number of times it appears
// in the string.
//
// Return the sorted string. If there are multiple answers, return any of them.
//
// Example 1:
//   Input:  s = "tree"
//   Output: "eert"
//   Explanation: 'e' appears twice while 'r' and 't' both appear once.
//   Therefore 'e' must appear before both 'r' and 't'. "eetr" is also valid.
//
// Example 2:
//   Input:  s = "cccaaa"
//   Output: "cccaaa"
//   Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also
//   valid. Note that "cacaca" is incorrect — same characters must be together.
//
// Example 3:
//   Input:  s = "Aabb"
//   Output: "bbAa"
//   Explanation: "bbaA" is also valid. 'A' and 'a' are treated as different
//   characters.
//
// Constraints:
//   - 1 <= s.length <= 5 * 10^5
//   - s consists of uppercase and lowercase English letters and digits.
// ============================================================

#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> countByChar{};
        
        for (char c : s) {
            countByChar[c] += 1;
        }

        std::string ret{};
        std::vector<std::pair<char, int>> pairs{countByChar.begin(), countByChar.end()};
        std::ranges::sort(pairs, std::greater{}, &std::pair<char, int>::second);

        ret.reserve(s.length());

        for (auto [c, count] : pairs) {
            ret.append(count, c);
        }
        
        return ret;
    }
};

int main() { return 0; }
