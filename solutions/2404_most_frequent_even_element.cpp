// URL: https://leetcode.com/problems/most-frequent-even-element/
// Difficulty: Easy
//
// Problem:
// Given an integer array nums, return the most frequent even element.
//
// If there is a tie, return the smallest one. If there is no such element,
// return -1.
//
// Example 1:
//   Input:  nums = [0,1,2,2,4,4,1]
//   Output: 2
//   Explanation: The even elements are 0, 2, and 4. Of these, 2 and 4 appear
//                the most (twice each). We return the smallest one, which is 2.
//
// Example 2:
//   Input:  nums = [4,4,4,9,2,4]
//   Output: 4
//   Explanation: 4 is the even element that appears the most.
//
// Example 3:
//   Input:  nums = [29,47,21,41,13,37,25,7]
//   Output: -1
//   Explanation: There is no even element.
//
// Constraints:
//   - 1 <= nums.length <= 2000
//   - 0 <= nums[i] <= 10^5

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        std::unordered_map<int, int> counts{};

        for (int num : nums) {
            if (num % 2 == 0) {
                counts[num]++;
            }
        }

        int result = -1;
        int max = -1;

        for (auto [num, count] : counts) {
            if (count > max) {
                result = num;
                max = count;
            } else if (count == max && (result == -1 || num < result)) {
                result = num;
            }
        }

        return result;
    }
};

int main() { return 0; }
