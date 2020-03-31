/* https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */

/* Approach 1: 分治法
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
    void flatten(TreeNode* root)
    {      
        divideAndConquer(root);
    }
    
    TreeNode* divideAndConquer(TreeNode *root)
    {
        if(root == nullptr) return nullptr;
        
        if(root->left == nullptr && root->right == nullptr) return root;
        
        TreeNode *lastLeft = divideAndConquer(root->left);
        TreeNode *lastRight = divideAndConquer(root->right);
        
        if(lastLeft)
        {
            lastLeft->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        return lastRight != nullptr ? lastRight : lastLeft;
    }
};

/* Approach 2: post order traversal
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
    void flatten(TreeNode* root)
    {
        TreeNode *next = nullptr;
        postOrder(root, next);
    }
    
    void postOrder(TreeNode *root, TreeNode* &next)
    {
        if(root == nullptr) return;
        
        postOrder(root->right, next);
        postOrder(root->left, next);
        
        root->right = next;
        root->left = nullptr; 
        next = root;
    }
};
