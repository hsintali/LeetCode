/* https://leetcode.com/problems/binary-tree-upside-down/ */

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
    TreeNode* upsideDownBinaryTree(TreeNode* root)
    {
        TreeNode *newRoot = nullptr;
        DFS(root, newRoot);
        
        return newRoot;
    }
    
    void DFS(TreeNode *node, TreeNode* &newRoot)
    {
        if(node == nullptr) return;
        
        if(newRoot == nullptr && node->left == nullptr)
        {
            newRoot = node;
            return;
        }
        
        DFS(node->left, newRoot);
        
        TreeNode *leftNode = node->left;
        
        leftNode->left = node->right;
        node->right = nullptr;
        
        leftNode->right = node;
        node->left = nullptr;
    }
};
