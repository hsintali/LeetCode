/* https://leetcode.com/problems/house-robber-ii/ */

/* Approach 1: dp
Intuition: Since House[1] and House[n] are adjacent, they cannot be robbed together. 
           Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
           depending on which choice offers more money. 
           Now the problem has degenerated to the House Robber, which is already been solved.

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int dp[3];
        
        // nums[0] ~ nums[nums.size() - 2]
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < nums.size() - 1; ++i)
        {
            dp[(i + 1 + 3) % 3] = max(dp[(i + 3) % 3], dp[(i - 1 + 3) % 3] + nums[i]);
        }
        int ans = dp[(nums.size() - 1) % 3];
        
        // nums[1] ~ nums[nums.size() - 1]
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 1; i < nums.size() - 1; ++i)
        {
            dp[(i + 1 + 3) % 3] = max(dp[(i + 3) % 3], dp[(i - 1 + 3) % 3] + nums[i + 1]);
        }
        ans = max(ans, dp[(nums.size() - 1) % 3]);
        
        return ans;
    }
};
