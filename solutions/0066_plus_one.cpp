// URL:        https://leetcode.com/problems/plus-one/
// Difficulty: Easy
//
// You are given a large integer represented as an integer array digits, where
// each digits[i] is the i-th digit of the integer. The digits are ordered from
// most significant to least significant in left-to-right order. The large
// integer does not contain any leading 0's.
//
// Increment the large integer by one and return the resulting array of digits.
//
// Example 1:
//   Input:  digits = [1,2,3]
//   Output: [1,2,4]
//   Explanation: 123 + 1 = 124
//
// Example 2:
//   Input:  digits = [4,3,2,1]
//   Output: [4,3,2,2]
//   Explanation: 4321 + 1 = 4322
//
// Example 3:
//   Input:  digits = [9]
//   Output: [1,0]
//   Explanation: 9 + 1 = 10
//
// Constraints:
//   - 1 <= digits.length <= 100
//   - 0 <= digits[i] <= 9
//   - digits does not contain any leading 0's.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto iter = digits.rbegin();

        while (iter != digits.rend()) {
            *iter += 1;

            if (*iter < 10) {
                return digits;
            }

            *iter = 0;
            iter++;
        }

        if (iter == digits.rend()) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main() { return 0; }
