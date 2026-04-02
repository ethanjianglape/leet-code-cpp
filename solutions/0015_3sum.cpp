// https://leetcode.com/problems/3sum/
// Difficulty: Medium
//
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.
//
// Example 1:
//   Input:  nums = [-1,0,1,2,-1,-4]
//   Output: [[-1,-1,2],[-1,0,1]]
//   Explanation:
//     nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//     nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//     nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//     The distinct triplets are [-1,0,1] and [-1,-1,2].
//     Notice that the order of the output and the order of the triplets does not matter.
//
// Example 2:
//   Input:  nums = [0,1,1]
//   Output: []
//   Explanation: The only possible triplet does not sum up to 0.
//
// Example 3:
//   Input:  nums = [0,0,0]
//   Output: [[0,0,0]]
//   Explanation: The only possible triplet sums up to 0.
//
// Constraints:
//   3 <= nums.length <= 3000
//   -10^5 <= nums[i] <= 10^5

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<int> copy = nums;
        std::sort(copy.begin(), copy.end());
        std::vector<std::vector<int>> result{};

        int i = 0;
        const int n = copy.size();

        while (i < n && copy[i] <= 0) {
            if (copy[i] > 0) {
                break;
            }

            int target = -copy[i];
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int a = copy[j];
                int b = copy[k];
                int sum = a + b;

                if (sum == target) {
                    result.push_back({copy[i], copy[j], copy[k]});
                    j++;
                    k--;

                    while (j < n && copy[j] == copy[j - 1]) j++;
                    while (k > 0 && copy[k] == copy[k + 1]) k--;
                } else if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }

            i++;

            while (i < n && copy[i] == copy[i - 1]) i++;
        }
        
        return result;
    }
};

int main() { return 0; }
