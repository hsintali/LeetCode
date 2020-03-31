/* https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/ */

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
    TreeNode* bstToGst(TreeNode* root)
    {
        int sum = 0;
        invertInorderTraversal(root, sum);

        return root;
    }
    
    void invertInorderTraversal(TreeNode *root, int &sum)
    {
        if(root == nullptr) return;

        invertInorderTraversal(root->right, sum);

        sum += root->val;
        root->val = sum;

        invertInorderTraversal(root->left, sum);
    }
};
