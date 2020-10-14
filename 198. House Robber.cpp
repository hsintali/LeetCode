/* https://leetcode.com/problems/house-robber/ */

/* Approach 1: dp
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        int dp[nums.size() + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[nums.size()];
    }
};

/* Approach 2: dp
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        int dp[3];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[(i + 1 + 3) % 3] = max(dp[(i + 3)% 3], dp[(i - 1 + 3) % 3] + nums[i]);
        }
        return dp[nums.size() % 3];
    }
};
