/* https://leetcode.com/problems/number-of-islands/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(m * n)
Space complexity: O(m * n)
*/

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int numIslands(vector<vector<char>>& grid)
    {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++count;
                    BFS(grid, n, m, i, j);
                }
            }
        }
        
        return count;
    }
    
    void BFS(vector<vector<char>> &grid, int n, int m, int x, int y)
    {
        if(grid[x][y] != '1') return;
            
        queue<pair<int, int>> que;
        que.push(make_pair(x, y));

        while(!que.empty())
        {
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            que.pop();

            for(int i = 0; i < 4; ++i)
            {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];

                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;

                if(grid[new_x][new_y] == '1')
                {
                    grid[new_x][new_y] = '0';
                    que.push(make_pair(new_x, new_y));
                }
            }
        }
    }
};
