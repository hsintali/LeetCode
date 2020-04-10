/* https://leetcode.com/problems/combination-sum/ */

/* Approach 1: DFS
Intuition:

Time complexity: O()
Space complexity: O()
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(candidates, target, 0, subset, 0, ans);
        
        return ans;
    }
    
    void dfs(vector<int> &candidates, int target, int startIndex, vector<int> &subset, int sum, vector<vector<int>> &ans)
    {
        if(sum == target) ans.push_back(subset);
        if(sum > target) return;
        
        for(int i = startIndex; i < candidates.size(); ++i)
        {
            subset.push_back(candidates[i]);
            dfs(candidates, target, i, subset, sum + candidates[i], ans);
            subset.pop_back();
        }
    }
};
