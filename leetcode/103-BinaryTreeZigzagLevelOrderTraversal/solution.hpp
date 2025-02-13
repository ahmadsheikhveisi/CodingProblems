/* COPYRIGHT
* Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
* (i.e., from left to right, then right to left for the next level and alternate between).
* 
*  
* 
* Example 1:
* 
* Input: root = [3,9,20,null,null,15,7]
* Output: [[3],[20,9],[15,7]]
* 
* Example 2:
* 
* Input: root = [1]
* Output: [[1]]
* 
* Example 3:
* 
* Input: root = []
* Output: []
* 
*  
* 
* Constraints:
* 
*     The number of nodes in the tree is in the range [0, 2000].
*     -100 <= Node.val <= 100
* 
* 
*/

#ifndef SYMMETRY_TREE_101
#define SYMMETRY_TREE_101

#include <queue>
#include <stack>
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
    std::vector<std::vector<int>> zigzagLevelOrder([[maybe_unused]] TreeNode* root) {
        std::vector<std::vector<int>> result{};
        if (root == nullptr) {
            return result;
        }
        std::stack<TreeNode*> qu{};
        bool left_to_right{false};
        qu.push(root);
        while (!qu.empty()) {
            auto size = qu.size();
            std::vector<int> row{};
            std::stack<TreeNode*> new_stack{};
            while (size > 0) {
                --size;
                auto node = qu.top();
                qu.pop();
                row.push_back(node->val);
                if (left_to_right) {
                    if (node->right != nullptr) {
                        new_stack.push(node->right);
                    }
                    if (node->left != nullptr) {
                        new_stack.push(node->left);
                    }
                } else {
                    if (node->left != nullptr) {
                        new_stack.push(node->left);
                    }
                    if (node->right != nullptr) {
                        new_stack.push(node->right);
                    }
                }
            }
            result.emplace_back(row);
            left_to_right = !left_to_right;
            qu = std::move(new_stack);
        }
        return result;
    }
 private:
};


#endif // SYMMETRY_TREE_101
