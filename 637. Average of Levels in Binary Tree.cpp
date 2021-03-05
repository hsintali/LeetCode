/* https://leetcode.com/problems/average-of-levels-in-binary-tree/ */

/* Approach 1: BFS
Intuition:

Time complexity:  O(n), where n is the number of nodes in the given binary tree
Space complexity: O(m), where m is the maximum number of nodes at any level in the tree
*/

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
    vector<double> averageOfLevels(TreeNode* root)
    {
        if(root == nullptr) return vector<double>();
        
        vector<double> ans;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty())
        {
            long long int sum = 0;
            
            int sizeCurLayer = que.size();
            for(int i = 0; i < sizeCurLayer; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();
                
                sum += cur->val;
                
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            
            ans.push_back((double)sum / sizeCurLayer);
        }
        
        return ans;
    }
};
