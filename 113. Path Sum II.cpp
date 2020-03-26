/* https://leetcode.com/problems/path-sum-ii/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V)
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
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> ans;
        
        if(root == nullptr) return ans;
        
        vector<int> path({root->val});
        DFS(root, sum, root->val, path, ans);
        
        return ans;
    }
    
    void DFS(TreeNode *root, int sum, int pathSum, vector<int> &path, vector<vector<int>> &ans)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            if(sum == pathSum) ans.push_back(path);
            return;
        }
        
        if(root->left != nullptr)
        {
            path.push_back(root->left->val);
            DFS(root->left, sum, pathSum + root->left->val, path, ans);
            path.pop_back();
        }
        
        if(root->right != nullptr)
        {
            path.push_back(root->right->val);
            DFS(root->right, sum, pathSum + root->right->val, path, ans);
            path.pop_back();
        }
    }
};
