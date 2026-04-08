// https://leetcode.com/problems/binary-tree-right-side-view/description/
// Difficulty: Medium
//
// Given the `root` of a binary tree, imagine yourself standing on the right
// side of it, return the values of the nodes you can see ordered from top to
// bottom.
//
// Example 1:
//   Input: root = [1,2,3,null,5,null,4]
//   Output: [1,3,4]
//
// Example 2:
//   Input: root = [1,2,3,4,null,null,null,5]
//   Output: [1,3,4,5]
//
// Example 3:
//   Input: root = [1,null,3]
//   Output: [1,3]
//
// Example 4:
//   Input: root = []
//   Output: []
//
// Constraints:
//   - The number of nodes in the tree is in the range [0, 100].
//   - -100 <= Node.val <= 100

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        
        std::vector<int> result{};
        std::deque<TreeNode*> queue{};

        queue.push_back(root);

        while (!queue.empty()) {
            int layerSize = queue.size();

            for (int i = 0; i < layerSize; i++) {
                TreeNode* top = queue.front();
                queue.pop_front();

                if (top->left) queue.push_back(top->left);
                if (top->right) queue.push_back(top->right);
                if (i == layerSize - 1) result.push_back(top->val);
            }
        }

        return result;
    }
};

int main() { return 0; }
