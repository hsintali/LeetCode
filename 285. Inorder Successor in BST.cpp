/* https://leetcode.com/problems/inorder-successor-in-bst/ */

/* Approach 1: BST
Intuition:

Time complexity: O(H)
Space complexity: O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        if(root == nullptr || p == nullptr) return nullptr;
        
        TreeNode *successor = nullptr;
        
        while(root != nullptr)
        {
            if(p->val < root->val)
            {
                successor = root;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        
        return successor;
    }
};
