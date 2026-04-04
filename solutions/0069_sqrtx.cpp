// https://leetcode.com/problems/sqrtx/
// Difficulty: Easy
//
// Given a non-negative integer x, return the square root of x rounded down to
// the nearest integer. The returned integer should be non-negative as well.
//
// You must not use any built-in exponent function or operator.
// For example, do not use pow(x, 0.5) in C++ or x ** 0.5 in Python.
//
// Example 1:
//   Input: x = 4
//   Output: 2
//   Explanation: The square root of 4 is 2, so we return 2.
//
// Example 2:
//   Input: x = 8
//   Output: 2
//   Explanation: The square root of 8 is 2.82842..., and since we round it
//   down to the nearest integer, 2 is returned.
//
// Constraints:
//   0 <= x <= 2^31 - 1

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        unsigned long target = x;

        unsigned long lower = 1;
        unsigned long upper = (target / 2) + 1;

        while (true) {
            unsigned long mid = lower + (upper - lower) / 2;
            unsigned long next = mid + 1;

            unsigned long midSqr = mid * mid;
            unsigned long nextSqr = next * next;

            if (midSqr <= target && nextSqr > target) {
                return mid;
            }

            if (midSqr > target) {
                // upper bound too high
                upper = mid;
            } else {
                // lower bound too low
                lower = mid;
            }
        }

        return -1;
    }
};

int main() { return 0; }
