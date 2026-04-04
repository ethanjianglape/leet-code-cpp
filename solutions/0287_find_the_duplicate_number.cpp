// https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty: Medium
//
// Given an array of integers nums containing n + 1 integers where each
// integer is in the range [1, n] inclusive.
//
// There is only one repeated number in nums, return this repeated number.
//
// You must solve the problem without modifying the array nums and uses
// only constant extra space.
//
// Example 1:
//   Input:  nums = [1,3,4,2,2]
//   Output: 2
//
// Example 2:
//   Input:  nums = [3,1,3,4,2]
//   Output: 3
//
// Example 3:
//   Input:  nums = [3,3,3,3,3]
//   Output: 3
//
// Constraints:
//   1 <= n <= 10^5
//   nums.length == n + 1
//   1 <= nums[i] <= n
//   There is only one repeated number in nums, though it could be repeated
//   more than once.
//
// Follow-up:
//   - How can we prove that at least one duplicate number must exist in nums?
//   - Can you solve the problem in linear runtime complexity?

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        int meeting = -1;

        auto next = [&nums](int i) { return nums[i]; };

        while (true) {
            slow = next(slow);
            fast = next(next(fast));

            if (slow == fast) {
                meeting = slow;
                break;
            }
        }

        if (meeting == -1) {
            return -1;
        }

        slow = nums[0];

        while (true) {
            if (slow == fast) {
                return slow;
            }

            slow = next(slow);
            fast = next(fast);
        }
        
        return -1;
    }
};

int main() { return 0; }
