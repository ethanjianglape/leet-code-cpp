// https://leetcode.com/problems/squares-of-a-sorted-array/
// Difficulty: Easy
//
// Given an integer array nums sorted in non-decreasing order, return an array
// of the squares of each number sorted in non-decreasing order.
//
// Example 1:
//   Input:  nums = [-4,-1,0,3,10]
//   Output: [0,1,9,16,100]
//   Explanation: After squaring, the array becomes [16,1,0,9,100].
//                After sorting, it becomes [0,1,9,16,100].
//
// Example 2:
//   Input:  nums = [-7,-3,2,3,11]
//   Output: [4,9,9,49,121]
//
// Constraints:
//   1 <= nums.length <= 10^4
//   -10^4 <= nums[i] <= 10^4
//   nums is sorted in non-decreasing order.
//
// Follow-up: Squaring each element and sorting the new array is very trivial,
// could you find an O(n) solution using a different approach?

#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> squared(nums.size(), 0);

        int i = 0;
        int j = nums.size() - 1;
        int insert = j;

        while (insert >= 0) {
            int front = nums[i] * nums[i];
            int back = nums[j] * nums[j];

            if (front >= back) {
                squared[insert--] = front;
                i++;
            } else {
                squared[insert--] = back;
                j--;
            }
        }
        
        return squared;
    }
};

int main() { return 0; }
