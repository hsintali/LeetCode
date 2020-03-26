/* https://leetcode.com/problems/binary-tree-maximum-path-sum/ */

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
    int maxPathSum(TreeNode* root)
    {
        if(root == nullptr) return 0;
        
        int maxPathSum = INT_MIN;
        DFS(root, maxPathSum);
        
        return maxPathSum;
    }
    
    // return local max path sum
    int DFS(TreeNode *root, int &maxPathSum)
    {
        if(root == nullptr) return 0;
        
        int left = max(0, DFS(root->left, maxPathSum));
        int right = max(0, DFS(root->right, maxPathSum));
        
        maxPathSum = max(maxPathSum, root->val + left + right);
        
        return root->val + max(left, right);
    }
};
