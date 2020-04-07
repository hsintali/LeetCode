/* https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/ */

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
    int longestConsecutive(TreeNode* root)
    {
        if(root == nullptr) return 0;
        
        int maxLen = 1;
        
        dfs(root, root->val, 1, maxLen);
        
        return maxLen;
    }
    
    void dfs(TreeNode *root, int val, int len, int &maxLen)
    {
        if(root == nullptr) return;
        
        if(root->val == val + 1)
        {
            ++len;
            maxLen = max(maxLen, len);
        }
        else
        {
            len = 1;
        }
        
        dfs(root->left, root->val, len, maxLen);
        dfs(root->right, root->val, len, maxLen);
    }
};
