/* https://leetcode.com/problems/validate-binary-search-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    bool isBST;
    TreeNode *maxNode = nullptr;
    TreeNode *minNode = nullptr;
        
    resultType(bool isBST)
    {
        this->isBST = isBST;
    }
        
    resultType(bool isBST, TreeNode *maxNode, TreeNode *minNode)
    {
        this->isBST = isBST;
        this->maxNode = maxNode;
        this->minNode = minNode;
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
    bool isValidBST(TreeNode* root)
    {
        return DFS(root).isBST;
    }
    
    // return is subtree a BST
    //        max node of subtree 
    //        min node of subtree
    resultType DFS(TreeNode *root)
    {
        if(root == nullptr) return resultType(true);
        
        resultType leftResult = DFS(root->left);
        if(leftResult.isBST == false) return resultType(false);
        
        resultType rightResult = DFS(root->right);
        if(rightResult.isBST == false) return resultType(false);
        
        if(leftResult.maxNode != nullptr && leftResult.maxNode->val >= root->val) return resultType(false);
        
        if(rightResult.minNode != nullptr && rightResult.minNode->val <= root->val) return resultType(false);
        
        TreeNode *maxNode = rightResult.maxNode != nullptr ? rightResult.maxNode : root;
        TreeNode *minNode = leftResult.minNode != nullptr ? leftResult.minNode : root;
        return resultType(true, maxNode, minNode);
    }
};
