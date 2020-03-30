/* https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/ */

/* Approach 1: DFS
Intuition: 當左右子樹的葉子深度都是整棵樹最深的時候 lca = root

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
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        TreeNode *lca = nullptr;
        int deepest = 0;
        cout << DFS(root, 0, deepest, lca);
        return lca;
    }
    
    int DFS(TreeNode *root, int depth, int &deepest, TreeNode* &lca)
    {
        if(root == nullptr)
        {
            deepest = max(deepest, depth);
            return depth;
        }
        
        int leftDepth = DFS(root->left, depth + 1, deepest, lca);
        int rightDepth = DFS(root->right, depth + 1, deepest, lca);
        
        if(leftDepth == deepest && rightDepth == deepest) lca = root;
        
        return max(leftDepth, rightDepth);
    }
};
