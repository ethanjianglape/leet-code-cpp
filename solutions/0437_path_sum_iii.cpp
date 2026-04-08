// https://leetcode.com/problems/path-sum-iii/description/
// Difficulty: Medium
//
// Given the `root` of a binary tree and an integer `targetSum`, return the
// number of paths where the sum of the values along the path equals `targetSum`.
//
// The path does not need to start or end at the root or a leaf, but it must
// go downwards (i.e., traveling only from parent nodes to child nodes).
//
// Example 1:
//   Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//   Output: 3
//   Explanation: The paths that sum to 8 are shown.
//
// Example 2:
//   Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//   Output: 3
//
// Constraints:
//   - The number of nodes in the tree is in the range [0, 1000].
//   - -10^9 <= Node.val <= 10^9
//   - -1000 <= targetSum <= 1000

#include <algorithm>
#include <string>
#include <unordered_map>
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
    std::unordered_map<long, int> prefixes;
    
    int pathSum2(TreeNode* node, long targetSum, long currentSum) {
        if (node == nullptr) return 0;

        currentSum += node->val;
        
        int count = 0;

        if (prefixes[currentSum - targetSum] > 0) {
            count = prefixes[currentSum - targetSum];
        }

        prefixes[currentSum]++;
        
        count +=
            pathSum2(node->left, targetSum, currentSum) +
            pathSum2(node->right, targetSum, currentSum);
        
        prefixes[currentSum]--;
        
        return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        prefixes[0] = 1;

        return pathSum2(root, targetSum, 0);
    }
};

int main() { return 0; }
