// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
// Difficulty: Medium
//
// Given the `root` of a binary tree, the level of its root is 1, the level of
// its children is 2, and so on.
//
// Return the smallest level x such that the sum of all the values of nodes at
// level x is maximal.
//
// Example 1:
//   Input: root = [1,7,0,7,-8,null,null]
//   Output: 2
//   Explanation:
//     Level 1 sum = 1.
//     Level 2 sum = 7 + 0 = 7.
//     Level 3 sum = 7 + -8 = -1.
//     So we return the level with the maximum sum which is level 2.
//
// Example 2:
//   Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
//   Output: 2
//
// Constraints:
//   - The number of nodes in the tree is in the range [1, 10^4].
//   - -10^5 <= Node.val <= 10^5

#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 0;

        std::deque<TreeNode*> queue;

        queue.push_back(root);

        std::optional<int> maxSum;
        int maxSumLevel = 0;
        int level = 1;

        while (!queue.empty()) {
            int nodes = queue.size();
            int sum = 0;

            while (nodes-- > 0) {
                TreeNode* n = queue.front();
                queue.pop_front();

                sum += n->val;

                if (n->left) queue.push_back(n->left);
                if (n->right) queue.push_back(n->right);
            }

            if (!maxSum.has_value() || sum > maxSum) {
                maxSum = sum;
                maxSumLevel = level;
            }

            level++;
        }

        return maxSumLevel;
    }
};

int main() { return 0; }
