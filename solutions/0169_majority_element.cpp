// URL: https://leetcode.com/problems/majority-element/
// Difficulty: Easy
//
// Problem:
// Given an array nums of size n, return the majority element.
//
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.
//
// Example 1:
//   Input:  nums = [3,2,3]
//   Output: 3
//
// Example 2:
//   Input:  nums = [2,2,1,1,1,2,2]
//   Output: 2
//
// Constraints:
//   - n == nums.length
//   - 1 <= n <= 5 * 10^4
//   - -10^9 <= nums[i] <= 10^9
//
// Follow-up: Could you solve the problem in linear time and in O(1) space?

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> counts{};

        for (int num : nums) {
            counts[num]++;
        }

        for (auto [num, count] : counts) {
            if (count > nums.size() / 2) {
                return num;
            }
        }

        return 0;
    }

    int majorityElement_BoyerMoore(vector<int>& nums) {
        int m = 0;
        int c = 0;

        for (int num : nums) {
            if (c == 0) {
                m = num;
                c = 1;
            } else if (m == num) {
                c++;
            } else {
                c--;
            }
        }

        return m;
    }
};

int main() { return 0; }
