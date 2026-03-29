// URL: https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Difficulty: Easy
//
// ============================================================
// 387. First Unique Character in a String
// ============================================================
//
// Given a string s, find the first non-repeating character in it and return
// its index. If it does not exist, return -1.
//
// Example 1:
//   Input:  s = "leetcode"
//   Output: 0
//   Explanation: The character 'l' at index 0 appears only once.
//
// Example 2:
//   Input:  s = "loveleetcode"
//   Output: 2
//   Explanation: The character 'v' at index 2 appears only once.
//
// Example 3:
//   Input:  s = "aabb"
//   Output: -1
//   Explanation: There is no unique character.
//
// Constraints:
//   - 1 <= s.length <= 10^5
//   - s consists of only lowercase English letters.
// ============================================================

#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> countByChar{};

        for (char c : s) {
            countByChar[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (countByChar[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() { return 0; }
