/* https://leetcode.com/problems/combination-sum-iii/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        
        dfs(k, n, 1, subset, 0, ans);
        
        return ans;
    }
    
    void dfs(int k, int n, int startIndex, vector<int> &subset, int sum, vector<vector<int>> &ans)
    {
        if(subset.size() == k && sum == n) ans.push_back(subset);
        
        if(subset.size() >= k) return;
        
        if(sum >= n) return;
        
        for(int i = startIndex; i <= 9; ++i)
        {
            subset.push_back(i);
            dfs(k, n, i + 1, subset, sum + i, ans);
            subset.pop_back();
        }
    }
};
