/* https://leetcode.com/problems/minimum-knight-moves/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(steps)
Space complexity: O(steps)
*/

class Solution {
public:
    int minKnightMoves(int x, int y)
    {
        if(x == 0 && y == 0) return 0;
        
        int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
        int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
        
        unordered_map<int, unordered_map<int, bool>> visited;
        
        queue<pair<int, int>> que; 
        que.push({0, 0});
        visited[0][0] = true;
        
        for(int steps = 1; !que.empty(); ++steps)
        {
            int size = que.size();
            for(int num = 0; num < size; ++num)
            {
                int cur_x = que.front().first;
                int cur_y = que.front().second;
                que.pop();
                
                for(int i = 0; i < 8; ++i)
                {
                    int new_x = cur_x + dx[i];
                    int new_y = cur_y + dy[i];
                    
                    if(new_x == x && new_y == y)
                    {
                        return steps;
                    }
                    
                    if(visited[new_x][new_y] == false && (new_x * x >= 0 || new_y * y >= 0))
                    {
                        visited[new_x][new_y] = true;
                        que.push({new_x, new_y});
                    }
                }
            }
        }
        
        return -1;
    }
};

/* Approach 1-2: BFS (Speedup)
Intuition:

Time complexity: O(steps)
Space complexity: O(steps)
*/

class Solution {
public:
    int minKnightMoves(int x, int y)
    {
        if(x == 0 && y == 0) return 0;
        
        x = abs(x);
        y = abs(y);
        
        int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
        int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
        
        // from -5 ~ 305
        vector<vector<bool>> visited(311, vector<bool>(311, false));
        
        queue<pair<int, int>> que; 
        que.push({0, 0});
        visited[5][5] = true;
        
        for(int steps = 1; !que.empty(); ++steps)
        {
            int size = que.size();
            for(int num = 0; num < size; ++num)
            {
                int cur_x = que.front().first;
                int cur_y = que.front().second;
                que.pop();
                
                for(int i = 0; i < 8; ++i)
                {
                    int new_x = cur_x + dx[i];
                    int new_y = cur_y + dy[i];
                    
                    if(new_x == x && new_y == y)
                    {
                        return steps;
                    }
                    
                    if(visited[new_x + 5][new_y + 5] == true) continue;
                    if(abs(new_x - x) + abs(new_y - y) > 300) continue;
                    if(new_x < -2 || new_y < -2) continue;
                    if(new_x > x + 2 || new_y > y + 2) continue;
                    
                    visited[new_x + 5][new_y + 5] = true;
                    que.push({new_x, new_y});
                }
            }
        }
        
        return -1;
    }
};
