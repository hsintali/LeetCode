/* https://leetcode.com/problems/binary-tree-postorder-traversal/ */

/* Approach 1: Recursion
Intuition:

Time complexity: O(n)
Space complexity: O(n)
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        postorder(root, ans);
        
        return ans;
    }
    
    void postorder(TreeNode* root, vector<int> &ans)
    {
        if(root == nullptr) return;
        
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
};
