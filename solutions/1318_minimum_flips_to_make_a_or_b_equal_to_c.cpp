// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
// Difficulty: Medium
//
// Given 3 positive numbers a, b and c. Return the minimum flips required in
// some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
// Flip operation consists of changing any single bit 1 to 0 or changing the
// bit 0 to 1 in their binary representation.
//
// Example 1:
//   Input: a = 2, b = 6, c = 5
//   Output: 3
//   Explanation: After flips a = 1, b = 4, c = 5 such that (a OR b == c)
//
// Example 2:
//   Input: a = 4, b = 2, c = 7
//   Output: 1
//
// Example 3:
//   Input: a = 1, b = 2, c = 3
//   Output: 0
//
// Constraints:
//   - 1 <= a <= 10^9
//   - 1 <= b <= 10^9
//   - 1 <= c <= 10^9

#include <algorithm>
#include <climits>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
    template <typename T>
    requires std::is_integral_v<T> && std::is_unsigned_v<T>
    int minFlips(T a, T b, T c) {
        constexpr int bits = sizeof(a) * CHAR_BIT;

        int flips = 0;

        for (int bit = 0; bit < bits; bit++) {
            const int target = (c >> bit) & 1;
            const int abit   = (a >> bit) & 1;
            const int bbit   = (b >> bit) & 1;

            switch (target) {
            case 0:
                if (abit == 1) flips++;
                if (bbit == 1) flips++;
                break;
            case 1:
                if (abit == 0 && bbit == 0) flips++;
                break;
            }
        }
        
        return flips;
    }
};

int main() { return 0; }
