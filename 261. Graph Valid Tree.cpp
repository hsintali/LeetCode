/* https://leetcode.com/problems/graph-valid-tree/ */

/* Approach 1: BFS
Intuition: undirected: E = V - 1
           Coner Case: [0, 1] = [1, 0]，所以兩個都要加入到 neighbors 中

Time complexity: O(V + E) = O(n)
Space complexity: O(V + E) = O(n)
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if(n - 1 != edges.size()) return false;
        
        vector<vector<int>> neighbors(n, vector<int>());
        
        // get neighbors
        for(auto &edge : edges)
        {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        
        queue<int> que;
        que.push(0);
        visited.insert(0);
        
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            
            for(auto &neighbor : neighbors[cur])
            {
                if(visited.count(neighbor) == 1) continue;
                
                que.push(neighbor);
                visited.insert(neighbor);
            }
        }
        
        return visited.size() == n;
    }
};
