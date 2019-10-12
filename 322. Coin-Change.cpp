/* https://leetcode.com/problems/coin-change/ */

/* Approach 1: DP
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int a[amount + 1] = {0};            
        for(int i = 1; i <= amount; ++i)
        {
            a[i] = amount + 1;
        }
                
        for(int i = 1; i <= amount; ++i)
        {
            for(int j = 0; j < coins.size(); ++j)
            {
                int index = i - coins[j];
                if(index < 0)
                    continue;
                
                a[i] = min(a[i], a[index] + 1);
            }
        }
        
        return a[amount] == amount + 1 ? -1 : a[amount];
    }
};
