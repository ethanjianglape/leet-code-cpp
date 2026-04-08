// https://leetcode.com/problems/symmetric-tree/description/
// Difficulty: Easy
//
// Given the `root` of a binary tree, check whether it is a mirror of itself
// (i.e., symmetric around its center).
//
// Example 1:
//   Input: root = [1,2,2,3,4,4,3]
//   Output: true
//
// Example 2:
//   Input: root = [1,2,2,null,3,null,3]
//   Output: false
//
// Constraints:
//   - The number of nodes in the tree is in the range [1, 1000].
//   - -100 <= Node.val <= 100
//
// Follow up: Could you solve it both recursively and iteratively?

#include <algorithm>
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
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        if (l->val != r->val) return false;

        return isSymmetric(l->left, r->right) &&
               isSymmetric(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left, root->right);
    }
};

int main() { return 0; }
