// URL:        https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
// Difficulty: Medium
//
// You are given two strings s1 and s2, both of length n, consisting of lowercase
// English letters.
//
// You can apply the following operation on any of the two strings any number of times:
//   - Choose any two indices i and j such that i < j and the difference j - i is
//     even, then swap the two characters at those indices in the string.
//
// Return true if you can make the strings s1 and s2 equal, and false otherwise.
//
// Example 1:
//   Input:  s1 = "abcdba", s2 = "cabdab"
//   Output: true
//   Explanation: We can apply the following operations on s1:
//     - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
//     - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
//     - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
//
// Example 2:
//   Input:  s1 = "abe", s2 = "bea"
//   Output: false
//   Explanation: It is not possible to make the two strings equal.
//
// Constraints:
//   - n == s1.length == s2.length
//   - 1 <= n <= 10^5
//   - s1 and s2 consist only of lowercase English letters.

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        std::unordered_map<char, int> evens{};
        std::unordered_map<char, int> odds{};

        for (int i = 0; i < s1.size(); i++) { 
            if (i % 2 == 0) {
                evens[s1[i]]++;
            } else {
                odds[s1[i]]++;
            }
        }

        for (int i = 0; i < s2.size(); i++){ 
            auto c = s2[i];
            auto& map = i % 2 == 0 ? evens : odds;

            if (!map.contains(c)) {
                return false;
            }

            if (map[c] == 0) {
                return false;
            }

            map[c]--;
        }

        return true;
    }
};

int main() { return 0; }
