/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {   
        if(root == nullptr) return nullptr;
        
        if(p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p ,q);
        }
        
        if(p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p ,q);
        }
        
        return root;
    }
};

/* Approach 2: DFS (iterativa)
Intuition:

Time complexity: O(V)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {   
        if(root == nullptr) return nullptr;
        
        TreeNode *node = root;
        
        while(node != nullptr)
        {
            if(p->val > node->val && q->val > node->val)
            {
                node = node->right;
            }
            else if(p->val < node->val && q->val < node->val)
            {
                node = node->left;
            }
            else
            {
                return node;
            }
        }
        
        return nullptr;
    }
};
