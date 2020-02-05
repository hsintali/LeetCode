/* https://leetcode.com/problems/shortest-distance-from-all-buildings/ */

/* Approach 1: BFS
Intuition: 遍歷 grid，當找到 1 (building)時，開始 BFS，找到 0 (freely land) 的時候計算這塊空地到建築物距離。
           當所有的建築物都跑過一次 BFS 之後，每塊空地到所有建築物的距離總和也會被計算出來。
           注意:有些空地無法 reach 到某些建築物，所以要用 visited 計算每個空地計算距離的次數是否與建築物的數目相等。
          
Time complexity: O(mn*mn)
Space complexity: O(mn)
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid)
    {
        if(grid.size() == 0) return -1;
        
        int m = grid.size(); // # of row
        int n = grid[0].size(); // # of colum
        
        vector<vector<int>> dist(m, vector<int>(n, 0)); // distance from all buildings
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int numBuilding = 0;
        int ans = INT_MAX;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] != 1) continue; // search start with value 1
                
                ++numBuilding;
                BFS(grid, m, n, i, j, dist, visited, numBuilding - 1);
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(visited[i][j] != numBuilding) continue;
                
                ans = min(ans, dist[i][j]);
            }
        }
                
        return ans == INT_MAX ? -1 : ans;
    }
    
    void BFS(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dist, vector<vector<int>> &visited, int round)
    {
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        queue<pair<pair<int, int>, int>> que;
        que.push({{i, j}, 0}); // the start point with value 1, its distance is 0
            
        while(!que.empty())
        {
            auto centralCord = que.front().first;
            auto centralDist = que.front().second;
            que.pop();
            
            for(auto dir : directions)
            {
                int x = centralCord.first + dir.first;
                int y = centralCord.second + dir.second;
                
                if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] != round || grid[x][y] != 0)
                {
                    continue;
                }
                
                dist[x][y] += centralDist + 1;
                ++visited[x][y];
                
                que.push({{x, y}, centralDist + 1});
            }
        }  
    }
};
