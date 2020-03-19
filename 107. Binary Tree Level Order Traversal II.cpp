  
/* https://leetcode.com/problems/binary-tree-level-order-traversal-ii/ */

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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        queue<TreeNode*> que;
        que.push(root);
        ans.push_back({root->val});

        while(!que.empty())
        {
            vector<int> curLevel;

            int size = que.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();

                if(cur->left != nullptr)
                {
                    que.push(cur->left);
                    curLevel.push_back(cur->left->val);
                }

                if(cur->right != nullptr)
                {
                    que.push(cur->right);
                    curLevel.push_back(cur->right->val);
                }
            }

            if(!curLevel.empty()) ans.push_back(curLevel);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
