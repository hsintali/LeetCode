/* https://leetcode.com/problems/find-leaves-of-binary-tree/ */

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
    vector<vector<int>> findLeaves(TreeNode* root)
    {
        vector<vector<int>> ans;
        
        DFS(root, ans);
        
        return ans;
    }
    
    // return the level of the node
    int DFS(TreeNode *root, vector<vector<int>> &ans)
    {
        if(root == nullptr) return 0;
        
        int left = DFS(root->left, ans);
        int right = DFS(root->right, ans);
        
        int level = max(left, right) + 1;
        
        if(level > ans.size()) ans.push_back(vector<int>());
        
        ans[level - 1].push_back(root->val);
        
        return level;
    }
};
