/* https://leetcode.com/problems/coin-change-2/ */

/* Approach 1: DP
Intuition:

Time complexity:O(amount * coins.size())
Space complexity: O(amount)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        vector<unsigned int> dp(amount + 1, 0);
        
        dp[0] = 1;
        
        for(auto &n : coins)
        //for(int i = 1; i <= amount; ++i)
        {
            for(int i = 1; i <= amount; ++i)
            //for(auto &n : coins)
            {
                if(i - n >= 0) dp[i] += dp[i - n];
            }
        }
                        
        return dp[amount];
    }
};
