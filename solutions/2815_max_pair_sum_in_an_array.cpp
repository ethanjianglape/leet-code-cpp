// https://leetcode.com/problems/max-pair-sum-in-an-array/
// Difficulty: Easy
//
// You are given a 0-indexed integer array nums. You have to find the maximum
// sum of a pair of numbers from nums such that the maximum digit in both
// numbers are equal.
//
// Return the maximum sum, or -1 if no such pair exists.
//
// Example 1:
//   Input:  nums = [51,71,17,24,42]
//   Output: 88
//   Explanation: For i=1 and j=2, nums[i] and nums[j] have equal maximum
//   digits with a pair sum of 71 + 17 = 88. For i=3 and j=4, the pair sum
//   is 24 + 42 = 66. The answer is 88.
//
// Example 2:
//   Input:  nums = [1,2,3,4]
//   Output: -1
//   Explanation: No pair exists with equal maximum digits.
//
// Constraints:
//   2 <= nums.length <= 100
//   1 <= nums[i] <= 10^4

#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        auto largestDigit = [](int num) {
            int largest = 0;

            while (num > 0) {
                int digit = num % 10;
                num /= 10;
                largest = digit > largest ? digit : largest;
            }

            return largest;
        };

        std::vector<std::pair<int, int>> pairs{10, {-1, -1}};

        for (int num : nums) {
            int digit = largestDigit(num);
            std::pair<int, int>& pair = pairs[digit];
            
            if (num > pair.first) {
                pair.second = pair.first;
                pair.first = num;
            } else if (num > pair.second) {
                pair.second = num;
            }
        }

        int max = -1;

        for (auto [first, second] : pairs) {
            if (first > 0 && second > 0 && first + second > max) {
                max = first + second;
            }
        }

        return max;
    }
};

int main() { return 0; }
