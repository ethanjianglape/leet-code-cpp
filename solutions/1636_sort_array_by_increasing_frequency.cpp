// URL: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/
// Difficulty: Easy
//
// ============================================================
// 1636. Sort Array by Increasing Frequency
// ============================================================
//
// Given an array of integers nums, sort the array in increasing order based on
// the frequency of the values. If multiple values have the same frequency,
// sort them in decreasing order.
//
// Return the sorted array.
//
// Example 1:
//   Input:  nums = [1,1,2,2,2,3]
//   Output: [3,1,1,2,2,2]
//   Explanation: '3' has frequency 1, '1' has frequency 2, '2' has frequency 3.
//
// Example 2:
//   Input:  nums = [2,3,1,3,2]
//   Output: [1,3,3,2,2]
//   Explanation: '2' and '3' both have frequency 2, so sorted in decreasing order.
//
// Example 3:
//   Input:  nums = [-1,1,-6,4,5,-6,1,4,1]
//   Output: [5,-1,4,4,-6,-6,1,1,1]
//
// Constraints:
//   - 1 <= nums.length <= 100
//   - -100 <= nums[i] <= 100
// ============================================================

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> frequencies{};
        std::vector<int> ret;

        for (int num : nums) {
            frequencies[num]++;
        }

        std::vector<std::pair<int, int>> pairs{frequencies.begin(), frequencies.end()};
        std::ranges::sort(pairs, [](const auto& p1, const auto& p2) {
            // same frequency
            if (p1.second == p2.second) {
                return p1.first > p2.first;
            }

            return p1.second < p2.second;
        });

        ret.reserve(nums.size());

        for (auto [num, frequency] : pairs) {
            while (frequency-- > 0) {
                ret.push_back(num);
            }
        }

        return ret;
    }
};

int main() { return 0; }
