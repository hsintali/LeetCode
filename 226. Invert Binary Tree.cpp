/* https://leetcode.com/problems/invert-binary-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
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
    TreeNode* invertTree(TreeNode* root)
    {
        invert(root);
        return root;
    }
    
    void invert(TreeNode *root)
    {
        if(root == nullptr) return;
        
        invert(root->left);
        invert(root->right);
        
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;
    }
};
