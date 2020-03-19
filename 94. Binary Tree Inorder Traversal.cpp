/* https://leetcode.com/problems/binary-tree-inorder-traversal/ */

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        inorder(root, ans);
        
        return ans;
    }
    
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root == nullptr) return;
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};

/* Approach 2: Iterative
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        if(root == nullptr) return ans;
        
        stack<TreeNode *> stk;

        TreeNode *cur = root;
        
        while(!stk.empty() || cur != nullptr)
        {
            if(cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *node = stk.top();
                ans.push_back(node->val);
                stk.pop();
                cur = node->right;
            }
        }
        
        return ans;
    }
};
