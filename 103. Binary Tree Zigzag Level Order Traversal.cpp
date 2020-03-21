/* https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(n)
Space complexity: O(V + E) = O(n)
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        
        if(root == nullptr) return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        
        bool isLeftToRight = true;
        
        while(!que.empty())
        {
            int size = que.size();
            vector<int> levelList(size, 0);
                
            for(int i = 0; i < size; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();
                
                if(isLeftToRight) levelList[i] = cur->val;
                else levelList[size - i - 1] = cur->val;
                
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            
            isLeftToRight = !isLeftToRight;
            ans.push_back(levelList);
        }
        
        return ans;
    }
};
