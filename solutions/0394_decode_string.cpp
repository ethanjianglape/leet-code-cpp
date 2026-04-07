// https://leetcode.com/problems/decode-string/description/
// Difficulty: Medium
//
// Given an encoded string, return its decoded string.
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the
// square brackets is being repeated exactly k times. Note that k is guaranteed
// to be a positive integer.
//
// You may assume that the input string is always valid; there are no extra
// white spaces, square brackets are well-formed, etc. Furthermore, you may
// assume that the original data does not contain any digits and that digits are
// only for those repeat numbers, k. For example, there will not be input like
// `3a` or `2[4]`.
//
// The test cases are generated so that the length of the output will never
// exceed 10^5.
//
// Example 1:
//   Input: s = "3[a]2[bc]"
//   Output: "aaabcbc"
//
// Example 2:
//   Input: s = "3[a2[c]]"
//   Output: "accaccacc"
//
// Example 3:
//   Input: s = "2[abc]3[cd]ef"
//   Output: "abcabccdcdcdef"
//
// Constraints:
//   - 1 <= s.length <= 30
//   - s consists of lowercase English letters, digits, and square brackets '[]'.
//   - s is guaranteed to be a valid input.
//   - All the integers in s are in the range [1, 300].

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        std::vector<int> counts{};
        std::vector<string> strings{};

        string current;

        int count = 0;

        for (char c : s) {
            if (c == '[') {
                counts.push_back(count);
                strings.push_back(current);
                current = "";
                count = 0;
                continue;
            }

            if (c == ']') {
                int repeat = counts.back();
                string prev = strings.back();
                string insert;

                while (repeat-- > 0) {
                    insert.append(current);
                }

                counts.pop_back();
                strings.pop_back();

                current = prev + insert;
                continue;
            }

            if (c >= '0' && c <= '9') {
                int digit = c - '0';
                count *= 10;
                count += digit;
                continue;
            }

            current += c;
        }

        return current;
    }
};

int main() { return 0; }
