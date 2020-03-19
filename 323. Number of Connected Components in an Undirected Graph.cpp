/* https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/ */

/* Approach 1: BFS
Intuition: 

Time complexity: O(V + E) = O(n)
Space complexity: O(V + E) = O(n)
*/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> neighbors(n, vector<int>());
        
        for(auto &edge : edges)
        {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int v = 0; v < n; ++v)
        {
            if(visited[v] == false) ++count;
            
            BFS(v, neighbors, visited);
        }
        
        return count;
    }
    
    void BFS(int v, vector<vector<int>> &neighbors, vector<bool> &visited)
    {
        if(visited[v] == true) return;
        
        queue<int> que;
        que.push(v);
        visited[v] = true;
        
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            
            for(auto &neighbor : neighbors[cur])
            {
                if(visited[neighbor] == true) continue;
                
                que.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
};
