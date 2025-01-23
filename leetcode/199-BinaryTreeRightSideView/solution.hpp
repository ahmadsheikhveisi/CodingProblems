/* COPYRIGHT
* Given the root of a binary tree, imagine yourself standing on the right side of it,
* return the values of the nodes you can see ordered from top to bottom.
* 
* Example 1:
* 
* Input: root = [1,2,3,null,5,null,4]
* 
* Output: [1,3,4]
* 
* Explanation:
* 
* Example 2:
* 
* Input: root = [1,2,3,4,null,null,null,5]
* 
* Output: [1,3,4,5]
* 
* Explanation:
* 
* Example 3:
* 
* Input: root = [1,null,3]
* 
* Output: [1,3]
* 
* Example 4:
* 
* Input: root = []
* 
* Output: []
* 
* Constraints:
* 
*     The number of nodes in the tree is in the range [0, 100].
*     -100 <= Node.val <= 100
*/

#ifndef BINARY_TREE_RIGHT_SIDE_VIEW_199
#define BINARY_TREE_RIGHT_SIDE_VIEW_199

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
    std::vector<int> rightSideView([[maybe_unused]] TreeNode* root) {
        size_t level{0};
        std::vector<int> result{};
        rightSideView(root, level, result);
        return result;
    }
 private:
    void rightSideView(TreeNode* root, size_t level, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        if (level == result.size()) {
            result.push_back(root->val);
        }
        rightSideView(root->right, level + 1, result);
        rightSideView(root->left, level + 1, result);
    }
};


#endif // BINARY_TREE_RIGHT_SIDE_VIEW_199
