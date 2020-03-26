/* https://leetcode.com/problems/balanced-binary-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    int depth;
    bool isBalanced;
    
    resultType(int depth, bool isBalanced)
    {
        this->depth = depth;
        this->isBalanced = isBalanced;
    }
};

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
    bool isBalanced(TreeNode* root)
    {
        return DFS(root).isBalanced;
    }
    
    resultType DFS(TreeNode *root)
    {
        if(root == nullptr) return resultType(0, true);
        
        resultType leftNode = DFS(root->left);
        if(leftNode.isBalanced == false) return resultType(-1, false);
            
        resultType rightNode = DFS(root->right);
        if(rightNode.isBalanced == false) return resultType(-1, false);
        
        if(abs(leftNode.depth - rightNode.depth) > 1) return resultType(-1, false);
        
        int depth = max(leftNode.depth, rightNode.depth) + 1;
        return resultType(depth, true);
    }
};
