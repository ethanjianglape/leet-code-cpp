// https://leetcode.com/problems/add-binary/
// Difficulty: Easy
//
// Problem:
// Given two binary strings a and b, return their sum as a binary string.
//
// Example 1:
//   Input:  a = "11", b = "1"
//   Output: "100"
//
// Example 2:
//   Input:  a = "1010", b = "1011"
//   Output: "10101"
//
// Constraints:
//   - 1 <= a.length, b.length <= 10^4
//   - a and b consist only of '0' or '1' characters.
//   - Each string does not contain leading zeros except for the zero itself.

#include <deque>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;

        std::deque<char> result{};

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0) {
            char ad = i >= 0 ? a[i] : '0';
            char bd = j >= 0 ? b[j] : '0';
            int av = ad - '0';
            int bv = bd - '0';
            int sum = av + bv + carry;
            int digit = sum % 2;

            result.push_front(digit == 0 ? '0' : '1');

            carry = sum / 2;

            if (i >= 0) i--;
            if (j >= 0) j--;
        }

        if (carry > 0) {
            result.push_front('1');
        }

        return std::string(result.begin(), result.end());
    }
};

int main() { return 0; }
