/* https://leetcode.com/problems/rotting-oranges/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(m * n)
Space complexity: O(m * n)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> que;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 2)
                {
                    que.push(make_pair(i, j));
                }
            }
        }
        
        int count = 0;
        int level = -1;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!que.empty())
        {
            int sizeCurLevel = que.size();
            for(int numCurLevel = 0; numCurLevel < sizeCurLevel; ++numCurLevel)
            {    
                int cur_x = que.front().first;
                int cur_y = que.front().second;
                que.pop();

                for(int i = 0; i < 4; ++i)
                {
                    int new_x = cur_x + dx[i];
                    int new_y = cur_y + dy[i];

                    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;

                    if(grid[new_x][new_y] == 1)
                    {
                        que.push(make_pair(new_x, new_y));
                        grid[new_x][new_y] = 2;
                    }
                }
            }
            
            ++level;
        }
        
        if(level > 0) count = level;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                   return -1;
                }
            }
        }
        
        return count;
    }
};
