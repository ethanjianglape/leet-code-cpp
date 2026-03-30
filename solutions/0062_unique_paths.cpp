// https://leetcode.com/problems/unique-paths/
// Difficulty: Medium
//
// There is a robot on an m x n grid. The robot is initially located at the
// top-left corner (grid[0][0]) and tries to move to the bottom-right corner
// (grid[m-1][n-1]). The robot can only move either down or right at any point.
//
// Given the two integers m and n, return the number of possible unique paths
// that the robot can take to reach the bottom-right corner.
//
// The answer will be <= 2 * 10^9.
//
// Example 1:
//   Input:  m = 3, n = 7
//   Output: 28
//
// Example 2:
//   Input:  m = 3, n = 2
//   Output: 3
//   Explanation: From the top-left corner, there are 3 ways to reach the
//   bottom-right corner:
//     1. Right -> Down -> Down
//     2. Down -> Down -> Right
//     3. Down -> Right -> Down
//
// Constraints:
//   1 <= m, n <= 100

#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

        // set first row to all 1
        for (int col = 0; col < n; col++) {
            grid[0][col] = 1;
        }

        // set first col to all 1
        for (int row = 0; row < m; row++) {
            grid[row][0] = 1;
        }

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                int top  = grid[row - 1][col];
                int left = grid[row][col - 1];

                grid[row][col] = top + left;
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main() { return 0; }
