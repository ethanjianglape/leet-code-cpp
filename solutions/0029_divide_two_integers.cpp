// https://leetcode.com/problems/divide-two-integers/
// Difficulty: Medium
//
// Given two integers dividend and divisor, divide two integers without using
// multiplication, division, or the mod operator.
//
// The integer division should truncate toward zero, meaning the fractional
// part is discarded.
//
// Return the quotient after dividing dividend by divisor.
//
// Note: Assume the environment can only store integers within the 32-bit
// signed integer range: [-2^31, 2^31 - 1].
//   - If the quotient is strictly greater than 2^31 - 1, return 2^31 - 1.
//   - If the quotient is strictly less than -2^31, return -2^31.
//
// Example 1:
//   Input:  dividend = 10, divisor = 3
//   Output: 3
//   Explanation: 10 / 3 = 3.33333... which truncates to 3.
//
// Example 2:
//   Input:  dividend = 7, divisor = -3
//   Output: -2
//   Explanation: 7 / -3 = -2.33333... which truncates to -2.
//
// Constraints:
//   -2^31 <= dividend, divisor <= 2^31 - 1
//   divisor != 0

#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (divisor == dividend) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        int quotient = 0;
        bool negative = 
            (dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0);

        long posDividend = dividend < 0 ? -(long)dividend : dividend;
        long posDivisor = divisor < 0 ? -(long)divisor : divisor;

        while (posDividend >= posDivisor) {
            long largestDivisor = posDivisor;
            int k = 0;

            while (largestDivisor < posDividend >> 1) {
                largestDivisor <<= 1;
                k++;
            }

            posDividend -= largestDivisor;
            quotient += 1 << k;
        }

        return negative ? -quotient : quotient;
    }
};

int main() { return 0; }
