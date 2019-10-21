/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ */

/* Approach 1: DP
Intuition: 
2k + 1 stages: 1: before 1st buy (w/o stack)
               2: after 1st buy and before 1st sell (w/ stack)
               .
               .
               .
            2k-1: after k-1th sell and before kth buy (w/o stack)
              2k: after kth buy and before kth sell (w/ stack)
            2k+1: after kth sell (w/o stack)

Time complexity: O(nk)
Space complexity: O(k)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        if(n == 0 || k == 0) return 0;
        
        if(k > n / 2)
        {
            int result = 0;
            for(int i = 1; i < n; ++i)
            {
                if(prices[i] > prices[i - 1])
                {
                    result += prices[i] - prices[i - 1];
                }
            }
            
            return result;
        }
        
        int K = 2 * k + 1;
        
        int f[2][K + 1];
        for(int i = 0; i <= K; ++i)
        {
            f[0][i] = INT_MIN;
        }
        f[0][1] = 0;
        
        for(int i = 1; i <= n; ++i)
        {         
            for(int j = 1; j <= K; j += 2)
            {
                // keep state (w/o stack)
                f[i%2][j] = f[(i - 1)%2][j];
                    
                // sell stack today
                if(i > 1 && j > 1 && f[(i - 1)%2][j - 1] != INT_MIN)
                {
                    f[i%2][j] = max(f[(i - 1)%2][j], f[(i - 1)%2][j - 1] + (prices[i - 1] - prices[i - 2]));
                }
            }
            
            for(int j = 2; j <= K; j += 2)
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
        
        int result = INT_MIN;
        for(int i = 1; i <= K; i += 2)
        {
            result = max(result, f[n%2][i]);
        }
        return result;
    }
};
