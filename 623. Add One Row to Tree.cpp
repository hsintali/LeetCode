/* https://leetcode.com/problems/add-one-row-to-tree/ */

/* Approach 1: BFS
Intuition:
Time complexity: O(n), where n is the number of nodes
Space complexity: O(log(n))
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
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if(d == 1)
        {
            return new TreeNode(v, root, nullptr);
        }

        queue<TreeNode*> que;
        que.push(root);
        int level = 1;
        
        while(!que.empty())
        {
            if(level > d - 1) break;
            
            int levelSize = que.size();
            for(int i = 0; i < levelSize; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                
                if(level == d - 1)
                {
                    node->left = new TreeNode(v, node->left, nullptr);
                    node->right = new TreeNode(v, nullptr, node->right);
                }
                else
                {
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }
            }
            
            ++level;
        }
        
        return root;
    }
};
