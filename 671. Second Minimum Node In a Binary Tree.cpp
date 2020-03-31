/* https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/ */

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
    int findSecondMinimumValue(TreeNode* root)
    {
        if(root == nullptr) return -1;
        
        int ans = -1;
        int left = (root->left != nullptr)   ? root->left->val : -1;
        int right = (root->right != nullptr) ? root->right->val: -1;
        
        if(left == root->val)  left = findSecondMinimumValue(root->left);
        if(right == root->val) right = findSecondMinimumValue(root->right);
        
        if(left != -1 and right != -1) return min(left, right);
        
        if(left == -1) return right;    
        
        return left;
    }
};
