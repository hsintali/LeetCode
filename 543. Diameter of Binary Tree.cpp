/* https://leetcode.com/problems/diameter-of-binary-tree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    int left;
    int right;
    int maxPath;
    resultType(int left, int right, int maxPath)
    {
        this->left = left;
        this->right = right;
        this->maxPath = maxPath;
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
    int diameterOfBinaryTree(TreeNode* root)
    {
        return dfs(root).maxPath;
    }
    
    resultType dfs(TreeNode *root)
    {
        if(root == nullptr) return resultType(-1, -1, 0);
        
        resultType leftResult = dfs(root->left);
        resultType rightResult = dfs(root->right);
        
        int left = max(leftResult.left, leftResult.right) + 1;
        int right = max(rightResult.left, rightResult.right) + 1;
        int maxPath = left + right;
        maxPath = max(leftResult.maxPath, max(maxPath, rightResult.maxPath));
        
        return resultType(left, right, maxPath);
    }
};

/* Approach 1-2: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    int maxDepth;
    int maxPath;
    resultType(int maxDepth, int maxPath)
    {
        this->maxDepth = maxDepth;
        this->maxPath = maxPath;
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
    int diameterOfBinaryTree(TreeNode* root)
    {
        return dfs(root).maxPath;
    }
    
    resultType dfs(TreeNode *root)
    {
        if(root == nullptr) return resultType(-1, 0);
        
        resultType leftResult = dfs(root->left);
        resultType rightResult = dfs(root->right);
        
        int maxDepth = max(leftResult.maxDepth, rightResult.maxDepth) + 1;
        int maxPath = leftResult.maxDepth + 1 + rightResult.maxDepth + 1;
        maxPath = max(leftResult.maxPath, max(maxPath, rightResult.maxPath));
        
        return resultType(maxDepth, maxPath);
    }
};
