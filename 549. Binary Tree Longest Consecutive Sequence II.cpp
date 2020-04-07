/* https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    int incr;
    int decr;
    int maxLen;
    resultType(int incr, int decr, int maxLen)
    {
        this->incr = incr;
        this->decr = decr;
        this->maxLen = maxLen;
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
    int longestConsecutive(TreeNode* root)
    {
        return dfs(root).maxLen;
    }
    
    resultType dfs(TreeNode *root)
    {
        if(root == nullptr) return resultType(0, 0, 0);
        
        resultType left = dfs(root->left);
        resultType right = dfs(root->right);
        
        int incr = 1;
        int decr = 1;
        
        if(root->left != nullptr)
        {
            if(root->val == root->left->val + 1)
            {
                decr = left.decr + 1;
            }
            else if(root->val == root->left->val - 1)
            {
                incr = left.incr + 1;
            }
        }
        
        if(root->right != nullptr)
        {
            if(root->val == root->right->val + 1)
            {
                decr = max(decr, right.decr + 1);
            }
            else if(root->val == root->right->val - 1)
            {
                incr = max(incr, right.incr + 1);
            }
        }
        
        int maxLen = max(max(left.maxLen, right.maxLen), incr + decr - 1);
        
        return resultType(incr, decr, maxLen);
    }
};
