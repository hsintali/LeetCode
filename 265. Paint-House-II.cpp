/* https://leetcode.com/problems/paint-house-ii/ */

/* Approach 1: DP
Intuition:

Time complexity: O(nk)
Space complexity: O(k)
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs)
    {
        int n = costs.size();
        if(n == 0) return 0;
        int c = costs[0].size();
        if(c == 0) return 0;
        
        int f[2][c];
        for(int i = 0; i < c; ++i)
        {
            f[0][i] = 0;
        }
        
        // first i houses: 0, ..., i-1
        for(int i = 1; i <= n; ++i)
        {
            // find the 1st minimum and 2nd minimum
            int m1 = -1, m2 = -1; // index of 1st and 2nd minimum
            for(int j = 0; j < c; ++j)
            {
                // if less than 1st minimum
                if(m1 == -1 || f[(i - 1) % 2][j] < f[(i - 1) % 2][m1])
                {
                    m2 = m1;
                    m1 = j;
                }
                else if(m2 == -1 || f[(i - 1) % 2][j] < f[(i - 1) % 2][m2])
                {
                    m2 = j;
                }
            }
                            
            for(int j = 0; j < c; ++j)
            {
                if(j != m1)
                {
                    f[i%2][j] = f[(i - 1) % 2][m1] + costs[i - 1][j];
                }
                else
                {
                    if(c == 1) m2 = 0; // to prevent from index m2 = -1
                    f[i%2][j] = f[(i - 1) % 2][m2] + costs[i - 1][j];
                }
            }
        }
        
        int result = INT_MAX;
        for(int j = 0; j < c; ++j)
        {
            result = min(result, f[n%2][j]);
        }
        
        return result;
    }
};
