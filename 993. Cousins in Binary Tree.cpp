/* https://leetcode.com/problems/cousins-in-binary-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity:  O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    int depth_x;
    int depth_y;
    bool isCousins;
    
    resultType(int depth_x, int depth_y, bool isCousins)
    {
        this->depth_x = depth_x;
        this->depth_y = depth_y;
        this->isCousins = isCousins;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y)
    {        
        return dfs(root, x, y, 0).isCousins;
    }
    
    resultType dfs(TreeNode *root, int x, int y, int depth)
    {
        if(root == nullptr) return resultType(-1, -1, false);
        
        if(root->left && root->right)
        {
            if(root->left->val == x && root->right->val == y) return resultType(-1, -1, false);
            if(root->left->val == y && root->right->val == x) return resultType(-1, -1, false);
        }
        
        resultType left = dfs(root->left, x, y, depth + 1);
        resultType right = dfs(root->right, x, y, depth + 1);
                
        if(root->val == x) return resultType(depth, -1, false);
        if(root->val == y) return resultType(-1, depth, false);
        
        int depth_x = max(left.depth_x, right.depth_x);
        int depth_y = max(left.depth_y, right.depth_y);
        
        if(depth_x != -1 && depth_y != -1 && depth_x == depth_y) return resultType(depth_x, depth_y, true);
        
        return resultType(depth_x, depth_y, false);
    }
};
