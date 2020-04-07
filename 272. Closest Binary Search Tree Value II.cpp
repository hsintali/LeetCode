/* https://leetcode.com/problems/closest-binary-search-tree-value-ii/ */

/* Approach 1: DFS
Intuition:

Time complexity: O(V) = O(n)
Space complexity: O(H)
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
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        list<int> ans;
        
        inorder(root, target, k, ans);
        
        return vector<int>(ans.begin(), ans.end());
    }
    
    void inorder(TreeNode *root, double target, int k, list<int> &ans)
    {
        if(root == nullptr) return;
        
        inorder(root->left, target, k, ans);
        
        if(ans.size() == k && abs((double)root->val - target) < abs((double)ans.front() - target))
        {
            ans.pop_front();
            ans.push_back(root->val);
        }
        else if(ans.size() < k)
        {
            ans.push_back(root->val);
        }
        else
        {
            return;
        }
        
        inorder(root->right, target, k, ans);
    }
};

/* Approach 2: BST Iterator
Intuition:

Time complexity: O(H + k) = O(nlogn + k)
Space complexity: O(H)
*/

