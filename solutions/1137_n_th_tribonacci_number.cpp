// https://leetcode.com/problems/n-th-tribonacci-number/
// Difficulty: Easy
//
// The Tribonacci sequence T(n) is defined as follows:
//   T(0) = 0, T(1) = 1, T(2) = 1
//   For n >= 0: T(n+3) = T(n) + T(n+1) + T(n+2)
//
// Given n, return the value of T(n).
//
// Example 1:
//   Input:  n = 4
//   Output: 4
//   Explanation: T(3) = 0 + 1 + 1 = 2, T(4) = 1 + 1 + 2 = 4
//
// Example 2:
//   Input:  n = 25
//   Output: 1389537
//
// Constraints:
//   0 <= n <= 37
//   The answer is guaranteed to fit within a 32-bit integer.

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int total = 0;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;

        while (n-- >= 3) {
            total = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = total;
        }

        return total;
    }
};

int main() { return 0; }
