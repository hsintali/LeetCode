/* https://leetcode.com/problems/minimum-path-sum/ */

/* Approach 1: DP (1D)
Intuition:

Time complexity: O(mn)
Space complexity: O(n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        int f[2][n];
        int now = 0, old = 0;
        
        for(int i = 0; i < m; ++i)
        {
            now = old;
            old = 1 - now;
        
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 && j == 0)
                {
                    f[now][j] = grid[i][j];
                    continue;
                }
                
                f[now][j] = INT_MAX;
                
                // not at 1st row
                if(i > 0)
                {
                    f[now][j] = min(f[now][j], f[old][j] + grid[i][j]);
                }
                
                // not at 1st column
                if(j > 0)
                {
                    f[now][j] = min(f[now][j], f[now][j - 1] + grid[i][j]);
                }
            }
        }
        
        return f[now][n - 1];     
    }
};

/* Approach 2: DP (Without Extra Space)
Intuition: We can store the minimum sums in the original matrix itself, since we need not retain the original matrix here.

Time complexity: O(mn)
Space complexity: O(1)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 && j > 0)
                {
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                }
                else if(i > 0 && j == 0)
                {
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
                else if(i != 0 && j != 0)
                {
                    grid[i][j] = grid[i][j] + min(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
