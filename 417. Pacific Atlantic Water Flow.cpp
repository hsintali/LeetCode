/* https://leetcode.com/problems/pacific-atlantic-water-flow/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(m * n)
Space complexity: O(m * n)
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ans;
        
        if(matrix.size() == 0 || matrix[0].size() == 0) return ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // 00: not yet explored
        // 01: can reach pacific ocean
        // 10: can reach atlantic ocean
        // 11: can reach two oceans
        
        queue<pair<int, int>> que;
        
        for(int i = 0; i < n; ++i)
        {
            visited[i][0] |= 1;
            que.push(make_pair(i, 0));

            visited[i][m - 1] |= 2;
            que.push(make_pair(i, m - 1));
        }
        
        for(int j = 0; j < m; ++j)
        {
            visited[0][j] |= 1;
            que.push(make_pair(0, j));
            
            visited[n - 1][j] |= 2;
            que.push(make_pair(n - 1, j));
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!que.empty())
        {
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            que.pop();
            
            int curHeight = matrix[cur_x][cur_y];
            
            for(int i = 0; i < 4; ++i)
            {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];
                
                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
                
                int newHeight = matrix[new_x][new_y];
                
                if(curHeight > newHeight) continue;         
                if(visited[new_x][new_y] == 3 || visited[new_x][new_y] == visited[cur_x][cur_y]) continue;
                
                visited[new_x][new_y] |= visited[cur_x][cur_y];
                que.push(make_pair(new_x, new_y));
            }
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(visited[i][j] == 3)
                {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
