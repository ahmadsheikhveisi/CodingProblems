/* COPYRIGHT
* Given the root of a binary tree, return the average value of the nodes on
* each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
* 
*  
* 
* Example 1:
* 
* Input: root = [3,9,20,null,null,15,7]
* Output: [3.00000,14.50000,11.00000]
* Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
* Hence return [3, 14.5, 11].
* 
* Example 2:
* 
* Input: root = [3,9,20,15,7]
* Output: [3.00000,14.50000,11.00000]
* 
*  
* 
* Constraints:
* 
*     The number of nodes in the tree is in the range [1, 10^4].
*     -2^31 <= Node.val <= 2^31 - 1
* 
*/

#ifndef AVERAGE_OF_LEVELS_637
#define AVERAGE_OF_LEVELS_637

#include <list>
#include <queue>
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
/// @brief std queue takes less space compare to list and vector for stack
class Solution {
 public:
    std::vector<double> avergeOfLevels([[maybe_unused]] TreeNode* root) {
        std::vector<double> result{};
        std::queue<TreeNode*> stack{};
        stack.push(root);
        while(!stack.empty()) {
            double sum{0};
            auto q_size = stack.size();
            for (size_t i{0}; i < q_size; ++i) {
                auto node = stack.front();
                stack.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    stack.push(node->left);
                }
                if (node->right != nullptr) {
                    stack.push(node->right);
                }
            }
            result.push_back(sum/static_cast<double>(q_size));            
        }
        return result;
    }
 private:
};


#endif // AVERAGE_OF_LEVELS_637
