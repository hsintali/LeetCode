/* https://leetcode.com/problems/bomb-enemy/ */

/* Approach 1: DP
Intuition: Assume we can put the bomb at any cell for constructing transfer function.

Time complexity: O(mn)
Space complexity: O(mn)
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int up[m][n];
        int down[m][n];
        int left[m][n];
        int right[m][n];
        
        // up
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                up[i][j] = 0;
                
                if(grid[i][j] == 'W')
                {
                    continue;
                }
                    
                if(grid[i][j] == 'E')
                {
                    ++up[i][j];
                }   
                
                if(i > 0)
                {
                    up[i][j] += up[i - 1][j];
                }
            }
        }
        
        // left
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                left[i][j] = 0;
                
                if(grid[i][j] == 'W')
                {
                    continue;
                }
                    
                if(grid[i][j] == 'E')
                {
                    ++left[i][j];
                }   
                
                if(j > 0)
                {
                    left[i][j] += left[i][j - 1];
                }
            }
        }
        
        // down
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = 0; j < n; ++j)
            {
                down[i][j] = 0;
                
                if(grid[i][j] == 'W')
                {
                    continue;
                }
                    
                if(grid[i][j] == 'E')
                {
                    ++down[i][j];
                }   
                
                if(i < m - 1)
                {
                    down[i][j] += down[i + 1][j];
                }
            }
        }
        
        // right
        for(int i = 0; i < m; ++i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                right[i][j] = 0;
                
                if(grid[i][j] == 'W')
                {
                    continue;
                }
                    
                if(grid[i][j] == 'E')
                {
                    ++right[i][j];
                }   
                
                if(j < n - 1)
                {
                    right[i][j] += right[i][j + 1];
                }
            }
        }
        
        int result = 0;
        // sum
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '0')
                {
                    int sum = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                    result = max(result, sum);
                }
            }
        }
        
        return result;
    }
};
