/* https://leetcode.com/problems/kth-smallest-element-in-a-bst/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(n)
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
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> arr;
        
        inorder(root, arr);
        
        return arr[k - 1];
    }
    
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if(root == nullptr) return;
        
        inorder(root->left, arr);
        
        arr.push_back(root->val);
        
        inorder(root->right, arr);
    }
};

/* Approach 2: BST Iterator 模板
Intuition:

Time complexity: O(H + k)
Space complexity: O(H + k), because may k > H 
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
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> stk;
        TreeNode *node = root;
        int ans = -1;
        
        while(!stk.empty() || node != nullptr)
        {
            while(node != nullptr)
            {
                stk.push(node);
                node = node->left;
            }
            
            node = stk.top();
            stk.pop();
            
            if(--k == 0)
            {
                ans = node->val;
                break;
            }
                    
            node = node->right;
        }
        
        return ans;
    }
};
