/* https://leetcode.com/problems/path-sum/ */

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
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(root == nullptr) return false;
        
        return DFS(root, sum, root->val);
    }
    
    bool DFS(TreeNode* root, int sum, int pathSum)
    {
        if(root->left == nullptr and root->right == nullptr)
        {
            return sum == pathSum;
        }
        
        if(root->left && DFS(root->left, sum, pathSum + root->left->val) == true) return true;
        if(root->right && DFS(root->right, sum, pathSum + root->right->val) == true) return true;
        
        return false;
    }
};
