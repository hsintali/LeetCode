/* https://leetcode.com/problems/unique-paths-ii/ */

/* Approach 1: DP
Intuition:

Time complexity: O(mn)
Space complexity: O(mn)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        
        int m = obstacleGrid.size();
        int n =obstacleGrid[0].size();
        
        unsigned int f[m][n];
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    f[i][j] = 0;
                    continue;
                }
                
                if(i == 0 && j == 0)
                {
                    f[i][j] = 1;
                    continue;
                }
                
                f[i][j] = 0;
                
                // not at the 1st row
                if(i > 0)
                {
                    f[i][j] += f[i - 1][j];
                }
                
                // not at the 1st column
                if(j > 0)
                {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        
        return f[m - 1][n - 1];
    }
};
