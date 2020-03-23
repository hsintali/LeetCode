/* https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(mn)
Space complexity: O(mn)
*/

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid)
    {
        int m = grid.size();
        if(m == 0) return false;
        
        int n = grid[0].size();
        if(n == 0) return false;
        
        if(m == 1 && n == 1) return true;
        
        int dirs_x[6][2] = {{0, 0},  {-1, 1}, {0,  1}, {0, 1}, {0, -1}, {0, -1}};
        int dirs_y[6][2] = {{-1, 1}, {0, 0},  {-1, 0}, {1, 0}, {-1, 0}, {1, 0}};
        
        queue<pair<int,int>> que;
        que.push(make_pair(0, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        
        while(!que.empty())
        {
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            int cur_v = grid[cur_x][cur_y] - 1;
            
            que.pop();
            
            for(int i = 0; i < 2; ++i)
            {
                int new_x = cur_x + dirs_x[cur_v][i];
                int new_y = cur_y + dirs_y[cur_v][i];
                
                if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || visited[new_x][new_y] == 1) continue;
                
                int new_v = grid[new_x][new_y] - 1;
                
                if(new_x == m - 1 && new_y == n - 1)
                {
                    if(dirs_x[cur_v][i] == -dirs_x[new_v][0] && dirs_y[cur_v][i] == -dirs_y[new_v][0]) return true;
                    if(dirs_x[cur_v][i] == -dirs_x[new_v][1] && dirs_y[cur_v][i] == -dirs_y[new_v][1]) return true;
                }
                
                visited[new_x][new_y] = 1;
                que.push(make_pair(new_x, new_y));
            }
        }
        
        return false;
    }
};
