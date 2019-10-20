/* https://leetcode.com/problems/paint-house/ */

/* Approach 1: DP
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0 || costs[0].size() == 0)
            return 0;
        
        int n = costs.size();
        int f[2][3];
        f[0][0] = f[0][1] = f[0][2] = 0;
        int now= 1, old = 1;
        
        for(int i = 1; i <= n; ++i)
        {
            now = old;
            old = 1 - now;
            
            // i-1's color is j
            for(int j = 0; j < costs[0].size(); ++j)
            {
                f[now][j] = INT_MAX;
                
                // i-2's color is k
                for(int k = 0; k < costs[0].size(); ++k)
                {
                    if(j == k)
                        continue;
                    
                    f[now][j] = min(f[now][j], f[old][k] + costs[i - 1][j]);
                }
            }
        }
        
        return min(f[now][0], min(f[now][1], f[now][2]));
    }
};
