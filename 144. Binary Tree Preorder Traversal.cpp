/* https://leetcode.com/problems/binary-tree-preorder-traversal/ */

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        preorder(root, ans);
        
        return ans;
    }
    
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root == nullptr) return;
        
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};

/* Approach 2: Iterative
Intuition: 迭代版: while 裡面:根右左

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        if(root == nullptr) return ans;
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode *cur = stk.top();
            stk.pop();
            
            ans.push_back(cur->val);
            if(cur->right != nullptr) stk.push(cur->right);
            if(cur->left != nullptr) stk.push(cur->left);
        }
        
        return ans;
    }
};
