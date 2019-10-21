/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ */

/* Approach 1: DP
Intuition: 
5 stages: 1: before 1st buy (w/o stack)
          2: after 1st buy and before 1st sell (w/ stack)
          3: after 1st sell and before 2nd buy (w/o stack)
          4: after 2nd buy and before 2nd sell (w/ stack)
          5: after 2nd sell (w/o stack)

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if(n == 0) return 0;
        
        int f[2][5 + 1];
        f[0][1] = 0;
        f[0][2] = f[0][3] = f[0][4] = f[0][5] = INT_MIN;
        
        for(int i = 1; i <= n; ++i)
        {         
            for(int j = 1; j <= 5; ++j)
            {
                if(j == 1 || j == 3 || j == 5)
                {
                    // keep state (w/o stack)
                    f[i%2][j] = f[(i - 1)%2][j];
                    
                    // sell stack today
                    if(i > 1 && j > 1 && f[(i - 1)%2][j - 1] != INT_MIN)
                    {
                        f[i%2][j] = max(f[(i - 1)%2][j], f[(i - 1)%2][j - 1] + (prices[i - 1] - prices[i - 2]));
                    }
                }                
                else if(j == 2 || j == 4)
                {
                    // buy stack today
                    f[i%2][j] = f[(i - 1)%2][j - 1];
                    
                    // keep state (w/ stack)
                    if(i > 1 && f[(i - 1)%2][j] != INT_MIN)
                    {
                        f[i%2][j] = max(f[(i - 1)%2][j] + (prices[i - 1] - prices[i - 2]), f[(i - 1)%2][j - 1]);
                    }
                }
            }
        }
        
        return max(f[n%2][1], max(f[n%2][3], f[n%2][5]));
    }
};
