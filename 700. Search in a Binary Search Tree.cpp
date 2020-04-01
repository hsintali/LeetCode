/* https://leetcode.com/problems/search-in-a-binary-search-tree/ */

/* Approach 1: DFS (Iterative)
Intuition:

Time complexity: O(H)
Space complexity: O(1)
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
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root == nullptr) return root;
        
        TreeNode *node = root;
        
        while(node != nullptr)
        {
            if(val < node->val)
            {
                node = node->left;
            }
            else if (val > node->val)
            {
                node = node->right;
            }
            else if(val == node->val)
            {
                break;
            }
        }
        
        return node;
    }
};
