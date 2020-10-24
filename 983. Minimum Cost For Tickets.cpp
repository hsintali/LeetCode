/* https://leetcode.com/problems/minimum-cost-for-tickets/ */

/* Approach 1: dp
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        int dp[396] = {0};
        unordered_set<int> uset(days.begin(), days.end());
        for(int i = 31; i <= 395; ++i)
        {
            if(uset.count(i - 30) == 0)
            {
                dp[i] = dp[i - 1];
                continue;
            }
            
            dp[i] = dp[i - 1] + costs[0];
            dp[i] = min(dp[i], dp[i - 7] + costs[1]);
            dp[i] = min(dp[i], dp[i - 30] + costs[2]);
        }
        return dp[395];
    }
};
