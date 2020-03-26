/* https://leetcode.com/problems/path-sum-iii/ */

/* Approach 1: DFS (分治的分治) (雙重遞迴)
Intuition: findPaths(root, target): 找出從 root 開始走到最底，共有幾條路徑符合 sum == target。
           pathSum(root, sum): 找出從每個節點開始走到底，共有幾條路徑符合 sum == target。

Time complexity: O(V * H) ~= O(nlogn), worst: O(N^2)
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
    // O(H) ==> O(H * V)
    int pathSum(TreeNode* root, int sum)
    {
        if(root == nullptr) return 0;
        
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        
        return findPaths(root, sum) + left + right;
    }
    
    // O(V)
    // return the number of paths with sum == target
    int findPaths(TreeNode *root, int target)
    {
        if(root == nullptr) return 0;
        
        int left = findPaths(root->left, target - root->val);
        int right = findPaths(root->right, target - root->val);
        
        int ans = root->val == target ? 1 : 0;
        return ans + left + right;
    }
};

/* Approach 2: DFS
Intuition:

Time complexity: 
Space complexity: 
*/
