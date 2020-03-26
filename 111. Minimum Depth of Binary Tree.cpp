/* https://leetcode.com/problems/minimum-depth-of-binary-tree/ */

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
    int minDepth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        
        if(root->left == nullptr && root->right == nullptr) return 1;
        
        int min_depth = INT_MAX;
        if(root->left != nullptr) min_depth = min(min_depth, minDepth(root->left));
        if(root->right != nullptr) min_depth = min(min_depth, minDepth(root->right));
        
        return min_depth + 1;
    }
};
