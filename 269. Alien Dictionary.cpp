/* https://leetcode.com/problems/alien-dictionary/ */

/* Approach 1: Topological Sorting
Intuition: 難在看懂規則。words 中，
           s = word[i][j] 要與 t = word[i+1][j] 比，
           當 s != t 時，s -> t。然後要 break 繼續比下一對 word。

Time complexity: O(V + E), O(V) = O(26) = O(1); O(E) = O(V^2) = O(1) 
Space complexity: O(V + E)
*/

class Solution {
public:
    string alienOrder(vector<string>& words)
    {
        vector<vector<int>> graph(26, vector<int>());
        unordered_map<int, int> inDegree;
        
        // Init inDegree
        for(auto &word : words)
        {
            for(auto &c : word)
            {
                inDegree[charToInt(c)] = 0;
            }
        }
        
        // Convert to Grapth
        for(int i = 0; i < words.size() - 1; ++i)
        {
            string first = words[i];
            string second = words[i + 1];
            
            int minSize = min(first.size(), second.size());
            
            for(int j = 0; j < minSize; ++j)
            {
                // s -> t
                int s = charToInt(first[j]);
                int t = charToInt(second[j]);
                
                if(s != t)
                {
                    graph[s].push_back(t);
                    ++inDegree[t];
                    
                    break;
                }
            }
        }
        
        queue<int> que;
        
        // Find the start nodes
        for(auto &node : inDegree)
        {
            if(node.second == 0)
            {
                que.push(node.first);
            }
        }
        
        string ans;
        
        // Topologcal Sorting
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            ans.push_back(intToChar(cur));
            
            for(auto &neighbor : graph[cur])
            {
                --inDegree[neighbor];
                
                if(inDegree[neighbor] == 0)
                {
                    que.push(neighbor);
                }
            }
        }
        
        return ans.size() == inDegree.size() ? ans : "";
    }
    
    int charToInt(char &c)
    {
        return c - 'a';
    }
    
    char intToChar(int &n)
    {
        return 'a' + n;
    }
};
