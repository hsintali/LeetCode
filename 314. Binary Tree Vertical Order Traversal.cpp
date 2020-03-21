/* https://leetcode.com/problems/binary-tree-vertical-order-traversal/ */

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
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        
        if(root == nullptr) return ans;
        
        unordered_map<int, vector<int>> umap;
        
        int minCol = 0;
        
        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 0));
        umap[0].push_back(root->val);
        
        while(!que.empty())
        {
            TreeNode *cur = que.front().first;
            int curCol = que.front().second;
            que.pop();
            
            if(cur->left)
            {
                que.push(make_pair(cur->left, curCol - 1));
                umap[curCol - 1].push_back(cur->left->val);
                
                minCol = min(minCol, curCol - 1);
            }
            
            if(cur->right)
            {
                que.push(make_pair(cur->right, curCol + 1));   
                umap[curCol + 1].push_back(cur->right->val);
            }
        }
        
        while(umap.count(minCol) == 1)
        {
            ans.push_back(umap[minCol++]);
        }
        
        return ans;
    }
};
