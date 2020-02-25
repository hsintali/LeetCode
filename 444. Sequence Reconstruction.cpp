/* https://leetcode.com/problems/sequence-reconstruction/ */

/* Approach 1: Topological Sorting
Intuition: Coner Cases:
           1. org[i] 有可能不存在於 seqs 中，也就是不存在於 neighbors 中
           2. seqs 中的點有可能不屬於 [1, n] 的範圍內。

Time complexity: O(V + E)
Space complexity: O(V + E)
*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs)
    {
        int n = org.size();
        
        unordered_map<int, unordered_set<int>> neighbors;
        unordered_map<int, int> inDegree;

        // Convet seqs to neighbors
        for(auto &seq : seqs)
        {
            int size = seq.size();
 
            for(int i = 0; i < size; ++i)
            {
                if(seq[i] < 1 || seq[i] > n) return false; // coner case 2
                
                neighbors[seq[i]];
                
                if(i < size - 1 && neighbors[seq[i]].count(seq[i + 1]) == 0)
                {
                    if(seq[i + 1] < 1 || seq[i + 1] > n) return false; // coner case 2
                    
                    neighbors[seq[i]].insert(seq[i + 1]);
                    ++inDegree[seq[i + 1]];
                }
            }
        }
               
        queue<int> que;
        
        // Find the start nodes
        for(auto &node : org)
        {
            if(inDegree[node] == 0 && neighbors.count(node) == 1) // coner case 1
            {
                que.push(node);
            }
        }
        
        int count = 0;
        
        // Topological Sorting
        while(que.size() == 1)
        {
            int cur = que.front();
            que.pop();
            ++count;
            
            for(auto &neighbor : neighbors[cur])
            {
                --inDegree[neighbor];
                
                if(inDegree[neighbor] == 0)
                {
                    que.push(neighbor);
                }
            }
        }
        
        return count == org.size();
    }
};

/* Approach 1-2: Topological Sorting
Intuition: 允許重複的 neighbor，inDegteed 會重複計算到；但之後遍歷 neighbor 的時候還是會扣回來。
           如此可避免使用 hashSet:  unordered_map<int, unordered_set<int>> neighbors；
           inDegree 可改用 vector<int>，可避免使用 hashMap。所以實際上運行會比較快。

Time complexity: O(V + E)
Space complexity: O(V + E)
*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs)
    {        
        int n = org.size();
        
        unordered_map<int, vector<int>> neighbors;
        vector<int> inDegree(n + 1, 0);

        // Convet seqs to neighbors
        for(auto &seq : seqs)
        {
            int size = seq.size();
 
            for(int i = 0; i < size; ++i)
            {
                if(seq[i] < 1 || seq[i] > n) return false; // coner case 2
                
                neighbors[seq[i]];  
                
                if(i < size - 1)
                {
                    if(seq[i + 1] < 1 || seq[i + 1] > n) return false; // coner case 2
                    
                    neighbors[seq[i]].push_back(seq[i + 1]);
                    ++inDegree[seq[i + 1]];
                }
            }
        }
               
        queue<int> que;
        
        // Find the start nodes
        for(auto &node : org)
        {
            if(inDegree[node] == 0 && neighbors.count(node) == 1) // coner case 1
            {
                que.push(node);
            }
        }
        
        int count = 0;
        
        // Topological Sorting
        while(que.size() == 1)
        {
            int cur = que.front();
            que.pop();
            ++count;
            
            for(auto &neighbor : neighbors[cur])
            {
                --inDegree[neighbor];
                
                if(inDegree[neighbor] == 0)
                {
                    que.push(neighbor);
                }
            }
        }
        
        return count == org.size();
    }
};
