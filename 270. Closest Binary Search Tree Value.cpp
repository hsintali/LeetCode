/* https://leetcode.com/problems/closest-binary-search-tree-value/ */

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
    int closestValue(TreeNode* root, double target)
    {
        int closet = root->val;
        
        if(root->right && root->val < target)
        {
            closet = closestValue(root->right, target);
        }
        else if(root->left && root->val > target)
        {
            closet = closestValue(root->left, target);
        }
        
        closet = abs(closet - target) < abs(root->val - target) ? closet : root->val;
        
        return closet;
    }
};

/* Approach 2: DFS (Iterative)
Intuition:

Time complexity: O(V) = O(n)
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
    int closestValue(TreeNode* root, double target)
    {
        int closet = root->val;
        
        while(root != nullptr)
        {
            closet = abs(closet - target) < abs(root->val - target) ? closet : root->val;
            
            if(root->val < target)
            {
                root = root->right;
            }
            else if(root->val > target)
            {
                root = root->left;
            }
            else if(root->val == target)
            {
                break;
            }
        }
        
        return closet;
    }
};
