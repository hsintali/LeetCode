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

/* Approach 2: DFS + hash (prefix-sum)
Intuition: findPaths(root, target): 找出從 root 開始走到最底，共有幾條路徑符合 sum == target。
           利用 umap 紀錄走過路徑的 prefix-sum，再尋找 int diff = prefixSum - target，是否存在於之前的 prefix-sum。
           比如: 路徑 [10, 5, 3, 3] 當 DFS 走的時候其 prefix-sum 為 [10, 15, 18, 21]，而目標是 8，
                 Node 1: prefix-sum - target = 10 - 8 = 2, 2 不存在於之前的路徑
                 Node 2: prefix-sum - target = 15 - 8 = 7, 7 不存在於之前的路徑 
                 Node 3: prefix-sum - target = 18 - 8 = 10, 10 存在於之前的路徑 (18 - 10) = 8 (target)，
                         因此可以透過 umap 知道有多少種走法可以得到 prefix-sum = 10，就代表有多少種路徑可以走到 sum == target
                 Node 4: prefix-sum - target = 21 - 8 = 13, 13 不存在於之前的路徑 

Time complexity: O(V) = O(n)
Space complexity: O(V) = O(n)
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
    int pathSum(TreeNode* root, int sum)
    {
        unordered_map<int, int> umap;
        umap[0] = 1;
        
        return findPaths(root, sum, 0, umap);
    }
    
    // O(V)
    // return the number of paths with sum == target
    int findPaths(TreeNode *root, int target, int sofarSum, unordered_map<int, int> &umap)
    {
        if(root == nullptr) return 0;
        
        int ans = 0;
        
        sofarSum += root->val;
        int diff = sofarSum - target;
        if(umap.count(diff) == 1) ans += umap[diff];
        
        ++umap[sofarSum];
        int left = findPaths(root->left, target, sofarSum, umap);
        int right = findPaths(root->right, target, sofarSum, umap);
        --umap[sofarSum];
        
        return ans + left + right;
    }
};
