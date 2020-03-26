/* https://leetcode.com/problems/binary-tree-paths/ */

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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        
        if(root == nullptr) return ans;
        
        DFS(root, to_string(root->val), ans);
        
        return ans;
    }
    
    void DFS(TreeNode *root, string path, vector<string> &ans)
    {
        if(root->left == nullptr and root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }
        
        if(root->left != nullptr) DFS(root->left, path + "->" + to_string(root->left->val), ans);
        if(root->right != nullptr) DFS(root->right, path + "->" + to_string(root->right->val), ans);
    }
};
