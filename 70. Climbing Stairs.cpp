/* https://leetcode.com/problems/climbing-stairs/ */

class Solution {
public:
    int climbStairs(int n)
    {
        if(n <= 2) return n;
        
        int dp[2] = {1, 2};
        
        for(int i = 3; i <= n; ++i)
        {
            dp[(i - 1) % 2] = dp[0] + dp[1];
        }
        
        return dp[(n - 1) % 2];
    }
};
