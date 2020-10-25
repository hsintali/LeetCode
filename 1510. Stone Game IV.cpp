/* https://leetcode.com/problems/stone-game-iv/ */

/* Approach 1: DP
Intuition:

Time complexity:  O( n * sqrt(n) )
Space complexity: O(n)
*/

class Solution {
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);  
        for(int i = 1; i <= n; ++i)
        {
            for(int j = sqrt(i); j >=1; --j)
            {
                if(dp[i - j * j] == false)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
