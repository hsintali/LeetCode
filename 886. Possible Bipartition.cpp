/* https://leetcode.com/problems/possible-bipartition/ */

/* Approach 1: DFS
Intuition: 將 node 分成兩個 groups，與當前 node 相鄰的 neighbors 必須屬於另一個 group。
           若有一個 node 已經是 group 1 了，後來又被分成 group 0，此時產生 conflict，就不可能會是 bipartite。

Time complexity:  O(V + E)
Space complexity: O(V + E)
*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> graph(N + 1, vector<int>());     
        for(auto &edge : dislikes)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> nodeGroup(N + 1, -1);
        for(int node = 1; node <= N; ++node)
        {
            if(nodeGroup[node] == -1)
            {
                nodeGroup[node] = 0;
                
                if(dfs(node, graph, nodeGroup) == false)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &nodeGroup)
    {
        int newGroup = 1 - nodeGroup[node];
        
        for(auto &neighbor : graph[node])
        {
            if(nodeGroup[neighbor] == -1)
            {
                nodeGroup[neighbor] = newGroup;
                
                if(dfs(neighbor, graph, nodeGroup) == false)
                {
                    return false;
                }  
            }
            else if(nodeGroup[neighbor] != newGroup)
            {
                return false;      
            }   
        }
        
        return true;
    }
};

/* Approach 2: BFS
Intuition: 

Time complexity:  O(V + E)
Space complexity: O(V + E)
*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes)
    {
        
        vector<vector<int>> neighbors(N + 1, vector<int>());
        for(auto &edge : dislikes)
        {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        
        vector<int> nodeGroup(N + 1, -1);
        queue<int> que;
        
        for(int node = 0; node <= N; ++node)
        {
            if(nodeGroup[node] != -1) continue;
            
            que.push(node);
            nodeGroup[node] = 0;
            
            while(!que.empty())
            {
                int cur = que.front();
                que.pop();

                int newGroup = 1 - nodeGroup[cur];

                for(auto &neighbor : neighbors[cur])
                {
                    if(nodeGroup[neighbor] == -1)
                    {
                        nodeGroup[neighbor] = newGroup;
                        que.push(neighbor);  
                    }
                    else if(nodeGroup[neighbor] != newGroup)
                    {
                        return false;      
                    }         
                }
            }
        }
        
        return true;
    }
};
