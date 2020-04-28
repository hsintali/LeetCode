/* https://leetcode.com/problems/maximal-square/ */

/* Approach 1: DP
Intuition:

Time complexity:  O(mn)
Space complexity: O(mn)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        if(n == 0) return 0;
        
        int m = matrix[0].size();
        if(m == 0) return 0;
        
        int maxLen = 0;
        int dp[n + 1][m + 1];
        
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                dp[i][j] = 0;
                
                if(i < 1 || j < 1) continue;
                
                if(matrix[i - 1][j - 1] != '1') continue;
                
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        
        return maxLen * maxLen;
    }
};
