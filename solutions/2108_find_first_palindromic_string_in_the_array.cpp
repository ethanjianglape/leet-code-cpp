// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
// Difficulty: Easy
//
// Given an array of strings words, return the first palindromic string in the
// array. If there is no such string, return an empty string "".
//
// A string is palindromic if it reads the same forward and backward.
//
// Example 1:
//   Input:  words = ["abc","car","ada","racecar","cool"]
//   Output: "ada"
//   Explanation: The first palindromic string is "ada".
//                Note that "racecar" is also palindromic but is not the first.
//
// Example 2:
//   Input:  words = ["notapalindrome","racecar"]
//   Output: "racecar"
//
// Example 3:
//   Input:  words = ["def","ghi"]
//   Output: ""
//   Explanation: There are no palindromic strings, so "" is returned.
//
// Constraints:
//   1 <= words.length <= 100
//   1 <= words[i].length <= 100
//   words[i] consists only of lowercase English letters.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        auto isPalindrome = [](const string& str) {
            if (str.size() <= 1) return true;

            auto begin = str.begin();
            auto end = str.end() - 1;

            while (begin < end) {
                if (*begin != *end) {
                    return false;
                }

                begin++;
                end--;
            }

            return true;
        };

        for (const string& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }

        return "";
    }
};

int main() { return 0; }
