/* https://leetcode.com/problems/combination-sum-ii/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, 0, subset, 0, ans);
        
        return ans;
    }
    
    void dfs(vector<int> &candidates, int target, int startIndex, vector<int> &subset, int sum, vector<vector<int>> &ans)
    {
        if(sum > target) return;
        
        if(sum == target)
        {
            ans.push_back(subset);
            return;
        } // 1, 1, 2, 5, 6, 7, 10
                
        for(int i = startIndex; i < candidates.size(); ++i)
        {
            if(i > 0 && candidates[i] == candidates[i - 1] && i > startIndex) continue;
            
            subset.push_back(candidates[i]);
            dfs(candidates, target, i + 1, subset, sum + candidates[i], ans);
            subset.pop_back();
        }
    }
};
