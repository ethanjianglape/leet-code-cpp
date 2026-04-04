// https://leetcode.com/problems/summary-ranges/
// Difficulty: Easy
//
// Problem:
// You are given a sorted unique integer array nums.
//
// A range [a,b] is the set of all integers from a to b (inclusive).
//
// Return the smallest sorted list of ranges that cover all the numbers in the
// array exactly. That is, each element of nums is covered by exactly one of the
// ranges, and there is no integer x such that x is in one of the ranges but not
// in nums.
//
// Each range [a,b] in the list should be output as:
//   "a->b"  if a != b
//   "a"     if a == b
//
// Example 1:
//   Input:  nums = [0,1,2,4,5,7]
//   Output: ["0->2","4->5","7"]
//   Explanation:
//     [0,2] --> "0->2"
//     [4,5] --> "4->5"
//     [7,7] --> "7"
//
// Example 2:
//   Input:  nums = [0,2,3,4,6,8,9]
//   Output: ["0","2->4","6","8->9"]
//   Explanation:
//     [0,0] --> "0"
//     [2,4] --> "2->4"
//     [6,6] --> "6"
//     [8,9] --> "8->9"
//
// Constraints:
//   0 <= nums.length <= 20
//   -2^31 <= nums[i] <= 2^31 - 1
//   All the values of nums are unique.
//   nums is sorted in ascending order.

#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.empty()) return {};

        const int n = nums.size();
        int start = 0;

        std::vector<std::string> result{};

        for (int i = 0; i < n - 1; i++) {
            int num = nums[i];
            int next = nums[i + 1];

            if (num + 1 == next) {
                continue;
            }

            int diff = i - start;
            std::stringstream ss;

            if (diff == 0) {
                ss << nums[start];
            } else {
                ss << nums[start] << "->" << nums[i];
            }

            result.push_back(ss.str());
            start = i + 1;
        }

        std::stringstream ss;

        if (start == n - 1) {
            ss << nums[start];
        } else {
            ss << nums[start] << "->" << nums[n - 1];
        }

        result.push_back(ss.str());

        return result;
    }
};

int main() { return 0; }
