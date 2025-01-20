/* COPYRIGHT
* Given the root of a binary tree, check whether it is a mirror of itself
* (i.e., symmetric around its center).
* 
* Example 1:
* 
* Input: root = [1,2,2,3,4,4,3]
* Output: true
* 
* Example 2:
* 
* Input: root = [1,2,2,null,3,null,3]
* Output: false
* 
* Constraints:
* 
*     The number of nodes in the tree is in the range [1, 1000].
*     -100 <= Node.val <= 100
* 
* Follow up: Could you solve it both recursively and iteratively?
*/

#ifndef SYMMETRY_TREE_101
#define SYMMETRY_TREE_101

#include <vector>

/**
 * Definition for a binary tree node.
 */
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
    bool isSymmetricRecursive([[maybe_unused]] TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric([[maybe_unused]] TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        std::vector<TreeNode*> stack;
        stack.push_back(root->left);
        stack.push_back(root->right);
        while (!stack.empty()) {
            auto right = stack.back();
            stack.pop_back();
            auto left = stack.back();
            stack.pop_back();
            if ((left == nullptr) || (right == nullptr)) {
                if (left != right) {
                    return false;
                }
                continue;
            }
            if (left->val != right->val) {
                return false;
            }
            stack.push_back(left->left);
            stack.push_back(right->right);
            stack.push_back(left->right);
            stack.push_back(right->left);
        }
        return true;
    }
 private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if ((left == nullptr) || (right == nullptr)) {
            return left == right;
        }
        return (left->val == right->val) &&
            isSymmetric(left->left, right->right) &&
            isSymmetric(left->right, right->left);
    }
};


#endif // SYMMETRY_TREE_101
