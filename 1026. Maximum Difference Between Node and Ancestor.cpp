/* https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O()
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
    int maxAncestorDiff(TreeNode* root)
    {
        return DFS(root, INT_MIN, INT_MAX); 
    }
    
    int DFS(TreeNode *root, int maxVal, int minVal)
    {
        if(root == nullptr) return abs(maxVal - minVal);
        
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        
        int left = DFS(root->left, maxVal, minVal);
        int right = DFS(root->right, maxVal, minVal);
        
        return max(left, right);
    }
};
