/* https://leetcode.com/problems/maximum-average-subtree/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
*/

struct resultType
{
    int sum;
    int num;
    double maxAverage;
    
    resultType(int sum, int num, double maxAverage)
    {
        this->sum = sum;
        this->num = num;
        this->maxAverage = maxAverage;
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
    double maximumAverageSubtree(TreeNode* root)
    {
        return helper(root).maxAverage;
    }
    
    resultType helper(TreeNode *root)
    {
        if(root == nullptr) return resultType(0, 0, 0);
        
        resultType left = helper(root->left);
        resultType right = helper(root->right);
        
        int curSum = left.sum + right.sum + root->val;
        int curNum = left.num + right.num + 1;
        double curAverage = (double)(curSum) / (double)(curNum);
        
        double maxAverage = max(curAverage, max(left.maxAverage, right.maxAverage));
        
        return resultType(curSum, curNum, maxAverage);
    }
};
