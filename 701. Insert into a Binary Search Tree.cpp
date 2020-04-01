/* https://leetcode.com/problems/insert-into-a-binary-search-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(H)
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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        
        if(val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
};

/* Approach 2: DFS (Iterative)
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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode *node = root;
        
        while(node != nullptr)
        {
            if(val < node->val)
            {
                if(node->left)
                {
                    node = node->left;
                }
                else
                {
                    node->left = new TreeNode(val);
                    break;
                }
            }
            
            if(val > node->val)
            {
                if(node->right)
                {
                    node = node->right;
                }
                else
                {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};
