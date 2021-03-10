/* https://leetcode.com/problems/add-one-row-to-tree/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(n), where n is the number of nodes
Space complexity: O(log(n)), the number of maximum number of nodes at any level in the given tree
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

/* Approach 2: DFS (recursive)
Intuition: 

Time complexity: O(n), where n is the number of nodes
Space complexity: O(d), depth
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
        
        dfs(root, v, d, 1);
        
        return root;
    }
    
    void dfs(TreeNode *root, int v, int d, int level)
    {
        if(root == nullptr || level >= d) return;
        
        if(level < d - 1)
        {
            dfs(root->left, v, d, level + 1);
            dfs(root->right, v, d, level + 1);
        }
        else
        {
            root->left = new TreeNode(v, root->left, nullptr);
            root->right = new TreeNode(v, nullptr, root->right);
        }
    }
};

/* Approach 3: DFS (compact code without help function)
Intuition: In addition to use 1 to indicate attach to left node as required, 
              we can also use 0 to indicate attach to right node.

Time complexity: O(n), where n is the number of nodes
Space complexity: O(d), depth
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
        if(d < 2)
        {
            TreeNode *newNode = new TreeNode(v);
            (d == 1 ? newNode->left : newNode->right) = root;
            return newNode;
        }
        
        if(root)
        {
            root->left = addOneRow(root->left, v, d - 1);
            root->right = addOneRow(root->right, v, d - 1 - (d == 2));
        }
        
        return root;
    }
};

/* Approach 4: DFS (queue)
Intuition: 

Time complexity: O(n), where n is the number of nodes
Space complexity: O(d), depth
*/

