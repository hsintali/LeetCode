/* https://leetcode.com/problems/permutations-ii/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> subSet;
        vector<bool> visited(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, subSet, ans, visited);
        
        return ans;
    }
    
    void dfs(vector<int> &nums, vector<int> &subSet, vector<vector<int>> &ans, vector<bool> &visited)
    {
        if(subSet.size() == nums.size())
        {
            ans.push_back(subSet);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(visited[i] == true) continue;
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) continue;
            
            visited[i] = true;
            subSet.push_back(nums[i]);
            dfs(nums, subSet, ans, visited);
            subSet.pop_back();
            visited[i] = false;
        }
    }
};
