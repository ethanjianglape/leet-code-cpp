// https://leetcode.com/problems/merge-strings-alternately/
// Difficulty: Easy
//
// ============================================================
// 1768. Merge Strings Alternately
// ============================================================
//
// You are given two strings word1 and word2. Merge the strings
// by adding letters in alternating order, starting with word1.
// If a string is longer than the other, append the additional
// letters onto the end of the merged string.
//
// Return the merged string.
//
// ------------------------------------------------------------
// Example 1:
//   Input:  word1 = "abc", word2 = "pqr"
//   Output: "apbqcr"
//   Explanation:
//     word1:  a  b  c
//     word2:  p  q  r
//     merged: a  p  b  q  c  r
//
// Example 2:
//   Input:  word1 = "ab", word2 = "pqrs"
//   Output: "apbqrs"
//   Explanation:
//     word1:  a  b
//     word2:  p  q  r  s
//     merged: a  p  b  q  r  s
//     (word2 is longer, so "rs" is appended at the end)
//
// Example 3:
//   Input:  word1 = "abcd", word2 = "pq"
//   Output: "apbqcd"
//   Explanation:
//     word1:  a  b  c  d
//     word2:  p  q
//     merged: a  p  b  q  c  d
//     (word1 is longer, so "cd" is appended at the end)
//
// ------------------------------------------------------------
// Constraints:
//   - 1 <= word1.length, word2.length <= 100
//   - word1 and word2 consist of lowercase English letters.
// ============================================================

#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        if (word1.empty()) return word2;
        if (word2.empty()) return word1;

        std::string ret;

        ret.reserve(word1.size() + word2.size());

        int i = 0;

        while (i < word1.size() && i < word2.size()) {
            ret.push_back(word1[i]);
            ret.push_back(word2[i]);
            i++;
        }

        while (i < word1.size()) {
            ret.push_back(word1[i++]);
        }

        while (i < word2.size()) {
            ret.push_back(word2[i++]);
        }

        return ret;
    }
};

int main() { return 0; }
