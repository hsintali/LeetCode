/* https://leetcode.com/problems/sequence-reconstruction/ */

/* Approach 1: Topological Sorting
Intuition:

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
                if(seq[i] < 1 || seq[i] > n) return false;
                
                neighbors[seq[i]];
                
                if(i < size - 1 && neighbors[seq[i]].count(seq[i + 1]) == 0)
                {
                    neighbors[seq[i]].insert(seq[i + 1]);
                    ++inDegree[seq[i + 1]];
                }
            }
        }
               
        queue<int> que;
        
        // Find the start nodes
        for(auto &node : org)
        {
            if(inDegree[node] == 0 && neighbors.count(node) == 1)
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
