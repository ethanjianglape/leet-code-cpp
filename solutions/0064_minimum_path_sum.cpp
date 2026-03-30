// https://leetcode.com/problems/minimum-path-sum/
// Difficulty: Medium
//
// Given an m x n grid filled with non-negative numbers, find a path from the
// top-left to the bottom-right corner which minimizes the sum of all numbers
// along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example 1:
//   Input:  grid = [[1,3,1],[1,5,1],[4,2,1]]
//   Output: 7
//   Explanation: The path 1 -> 3 -> 1 -> 1 -> 1 minimizes the sum.
//
// Example 2:
//   Input:  grid = [[1,2,3],[4,5,6]]
//   Output: 12
//
// Constraints:
//   m == grid.length
//   n == grid[i].length
//   1 <= m, n <= 200
//   0 <= grid[i][j] <= 200

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid.front().size();

        // init row 0
        for (int col = 1; col < cols; col++) {
            grid[0][col] += grid[0][col - 1];
        }

        // init col 0
        for (int row = 1; row < rows; row++) {
            grid[row][0] += grid[row - 1][0];
        }

        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                int top =  grid[row - 1][col];
                int left = grid[row][col - 1];
                int min  = top < left ? top : left;

                grid[row][col] += min;
            }
        }

        return grid[rows - 1][cols - 1];
    }
};

int main() { return 0; }
