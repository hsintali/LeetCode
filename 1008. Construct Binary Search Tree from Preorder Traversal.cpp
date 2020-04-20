/* https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/ */

/* Approach 1: DFS (Traversal)
Intuition:

Time complexity:  O(n)
Space complexity: O(h)
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
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        if(preorder.size() == 0) return nullptr;
        
        TreeNode *head = new TreeNode(preorder[0]);
        int index = 1;
        dfs(head, preorder, index, INT_MIN, INT_MAX);
        return head;
    }
    
    void dfs(TreeNode *node, vector<int> &arr, int &index, int minVal, int maxVal)
    {
        if(index >= arr.size()) return;
        if(arr[index] <= minVal || arr[index] >= maxVal) return;
        
        if(arr[index] < node->val)
        {
            TreeNode *left = new TreeNode(arr[index]);
            node->left = left;
            ++index;
            dfs(left, arr, index, minVal, node->val);
        }
        
        if(index >= arr.size()) return;   
        if(arr[index] <= minVal || arr[index] >= maxVal) return;
        
        if(arr[index] > node->val)
        {
            TreeNode *right = new TreeNode(arr[index]);
            node->right = right;
            ++index;
            dfs(right, arr, index, node->val, maxVal);
        }
    }
};
