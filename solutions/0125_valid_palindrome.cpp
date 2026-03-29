// https://leetcode.com/problems/valid-palindrome/
// Difficulty: Easy
//
// A phrase is a palindrome if, after converting all uppercase letters to
// lowercase and removing all non-alphanumeric characters, it reads the same
// forward and backward. Alphanumeric characters include letters and digits.
//
// Given a string s, return true if it is a palindrome, or false otherwise.
//
// Example 1:
//   Input:  s = "A man, a plan, a canal: Panama"
//   Output: true
//   Explanation: "amanaplanacanalpanama" is a palindrome.
//
// Example 2:
//   Input:  s = "race a car"
//   Output: false
//   Explanation: "raceacar" is not a palindrome.
//
// Example 3:
//   Input:  s = " "
//   Output: true
//   Explanation: After removing non-alphanumeric characters, s is "".
//   An empty string reads the same forward and backward.
//
// Constraints:
//   1 <= s.length <= 2 * 10^5
//   s consists only of printable ASCII characters.

#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;

        auto begin = s.begin();
        auto end = s.end() - 1;

        while (begin < end) {
            while (!std::isalnum(*begin) && begin != end) begin++;
            while (!std::isalnum(*end) && end != begin) end--;

            if (begin > end) {
                return true;
            }

            if (std::tolower(*begin) != std::tolower(*end)) {
                return false;
            }

            begin++;
            end--;
        }

        return true;
    }
};

int main() { return 0; }
