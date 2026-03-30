// https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy
//
// Write a function to find the longest common prefix string amongst an array
// of strings. If there is no common prefix, return an empty string "".
//
// Example 1:
//   Input:  strs = ["flower","flow","flight"]
//   Output: "fl"
//
// Example 2:
//   Input:  strs = ["dog","racecar","car"]
//   Output: ""
//   Explanation: There is no common prefix among the input strings.
//
// Constraints:
//   1 <= strs.length <= 200
//   0 <= strs[i].length <= 200
//   strs[i] consists of only lowercase English letters if non-empty.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs.front();

        string prefix = strs.front();

        for (int i = 1; i < strs.size(); i++) {
            string& str = strs[i];

            int j = 0;

            while (j < prefix.size() && j < str.size() && prefix[j] == str[j]) {
                j++;
            }

            prefix.resize(j);

            if (prefix.empty()) {
                return "";
            }
        }

        return prefix;
    }
};

int main() { return 0; }
