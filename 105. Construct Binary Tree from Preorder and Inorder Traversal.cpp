/* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ */

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size() != inorder.size()) return nullptr;
        
        return divideAndConquer(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    // return root of subtree
    TreeNode* divideAndConquer(vector<int>& preorder, int i_pre, int j_pre, vector<int>& inorder, int i_in, int j_in)
    {
        if(i_pre > j_pre || i_in > j_in) return nullptr;
        
        int rootVal = preorder[i_pre];
        
        int index_in_root;
        for(int i = i_in; i <= j_in; ++i)
        {
            if(inorder[i] == rootVal) index_in_root = i;
        }
        int left_length = index_in_root - i_in;
        
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = divideAndConquer(preorder, i_pre + 1, i_pre + left_length, inorder, i_in, index_in_root - 1);
        root->right = divideAndConquer(preorder, i_pre + left_length + 1, j_pre, inorder, index_in_root + 1, j_in);
        
        return root;
    }
};
