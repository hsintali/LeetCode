/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ */

/* Approach 1: Dynamic Programming
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0) return 0;
        
        int minPrice = prices[0];
        int result = 0;
        
        for(int i = 1; i < prices.size(); ++i)
        {
            result = max(result, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        return result;
    }
};
