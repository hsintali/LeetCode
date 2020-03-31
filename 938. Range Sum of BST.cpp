/* https://leetcode.com/problems/range-sum-of-bst/ */

/* Approach 1: DFS
Intuition: 利用 BST 特性

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
    int rangeSumBST(TreeNode* root, int L, int R)
    { 
        return inorder(root, L, R);
    }
    
    int inorder(TreeNode *root, int L, int R)
    {
        if(root == nullptr) return 0;
        
        if(root->val < L)
        {
            return inorder(root->right, L, R);
        }
        
        if(root->val > R)
        {
            return inorder(root->left, L, R);
        }
        
        return root->val + inorder(root->left, L, R) + inorder(root->right, L, R);
    }
};

/* Approach 2: DFS
Intuition: 搜尋整棵樹

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
    int rangeSumBST(TreeNode* root, int L, int R)
    { 
        return DFS(root, L, R);
    }
    
    int DFS(TreeNode *root, int L, int R)
    {
        if(root == nullptr) return 0;
        
        int left = DFS(root->left, L, R);
        int right = DFS(root->right, L, R);
        
        int sum = left + right;
        
        if(root->val >= L && root->val <= R)
        {
            sum += root->val;
        }
        
        return sum;
    }
};
