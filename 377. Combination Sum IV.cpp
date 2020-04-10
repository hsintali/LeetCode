/* https://leetcode.com/problems/combination-sum-iv/ */

/* Approach 1: DFS (TLE)
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int ans = 0;
        
        dfs(nums, target, 0, ans);
        
        return ans;
    }
    
    void dfs(vector<int> &nums, int target, int sum, int &ans)
    {
        if(sum == target) ++ans;
        if(sum >= target) return;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            dfs(nums, target, sum + nums[i], ans);
        }
    }
};

/* Approach 2: DP
Intuition:

Time complexity:O(target * nums.size())
Space complexity: O(target)
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        
        dp[0] = 1;
        
        for(int i = 1; i <= target; ++i)
        {
            for(auto &n : nums)
            {
                if(i - n >= 0) dp[i] += dp[i - n];
            }
        }
                        
        return dp[target];
    }
};
