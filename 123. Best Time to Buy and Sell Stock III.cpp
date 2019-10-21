/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ */

/* Approach 1: DP
Intuition:

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
                    f[i%2][j] = f[(i - 1)%2][j];

                    if(i > 1 && j > 1 && f[(i - 1)%2][j - 1] != INT_MIN)
                    {
                        f[i%2][j] = max(f[(i - 1)%2][j], f[(i - 1)%2][j - 1] + (prices[i - 1] - prices[i - 2]));
                    }
                }                
                else if(j == 2 || j == 4)
                {
                    f[i%2][j] = f[(i - 1)%2][j - 1];
                    
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
