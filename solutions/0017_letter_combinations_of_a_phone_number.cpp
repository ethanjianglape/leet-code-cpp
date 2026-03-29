// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Difficulty: Medium
//
// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in
// any order.
//
// A mapping of digits to letters (like on a telephone keypad):
//   2 -> "abc"
//   3 -> "def"
//   4 -> "ghi"
//   5 -> "jkl"
//   6 -> "mno"
//   7 -> "pqrs"
//   8 -> "tuv"
//   9 -> "wxyz"
//
// Note that 1 does not map to any letters.
//
// Example 1:
//   Input:  digits = "23"
//   Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
// Example 2:
//   Input:  digits = ""
//   Output: []
//
// Example 3:
//   Input:  digits = "2"
//   Output: ["a","b","c"]
//
// Constraints:
//   0 <= digits.length <= 4
//   digits[i] is a digit in the range ['2', '9']

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        std::unordered_map<char, string> digitToChars{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        vector<string> results{""};

        for (char digit : digits) {
            vector<string> temp;
            string chars = digitToChars[digit];

            for (string& s : results) {
                for (char c : chars) {
                    temp.push_back(s + c);
                }
            }

            results = temp;
        }

        return results;
    }
};

int main() { return 0; }
