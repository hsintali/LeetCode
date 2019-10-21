/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/ */

/* Approach 1: Greedy
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0) return 0;
        
        int result = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] > prices[i -1])
            {
                result += prices[i] - prices[i - 1];
            }
        }
        
        return result;
    }
};
