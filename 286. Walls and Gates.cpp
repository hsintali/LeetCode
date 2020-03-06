/* https://leetcode.com/problems/walls-and-gates/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(m * n)
Space complexity: O(m * n)
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        if(rooms.size() == 0 || rooms[0].size() == 0) return;
        
        int n = rooms.size();
        int m = rooms[0].size();
        
        queue<pair<int, int>> que;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(rooms[i][j] == 0)
                {
                    que.push(make_pair(i, j));
                }
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
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
                
                if(rooms[new_x][new_y] == INT_MAX)
                {
                    que.push(make_pair(new_x, new_y));
                    rooms[new_x][new_y] = rooms[cur_x][cur_y] + 1;
                }
            }
        }
    }
};
