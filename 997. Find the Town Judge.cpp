/* https://leetcode.com/problems/find-the-town-judge/ */

/* Approach 1: HashMap (two unordered_map)
Intuition:

Time complexity:  O(N + E)
Space complexity: O(N)
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        if(N == 1) return 1;
        
        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        
        for(auto &pair : trust)
        {
            int a = pair[0];
            int b = pair[1];
            
            ++outDegree[a];
            ++inDegree[b];           
        }
        
        for(auto &it : inDegree)
        {
            if(it.second == N - 1 && outDegree[it.first] == 0)
            {
                return it.first;
            }
        }
        
        return -1;
    }
};

/* Approach 1-2: HashMap (two array)
Intuition:

Time complexity:  O(N + E)
Space complexity: O(N)
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        if(N == 1) return 1;
        
        vector<int> inDegree(N + 1, 0);
        vector<int> outDegree(N + 1, 0);
        
        for(auto &pair : trust)
        {
            int a = pair[0];
            int b = pair[1];
            
            ++outDegree[a];
            ++inDegree[b];           
        }
        
        for(int i = 1; i <= N; ++i)
        {
            if(inDegree[i] == N - 1 && outDegree[i] == 0)
            {
                return i;
            }
        }
        
        return -1;
    }
};

/* Approach 1-3: HashMap (one array)
Intuition:

Time complexity:  O(N + E)
Space complexity: O(N)
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        if(N == 1) return 1;
        
        vector<int> inOutDegree(N + 1, 0);
        
        for(auto &pair : trust)
        {
            int a = pair[0];
            int b = pair[1];
            
            --inOutDegree[a];
            ++inOutDegree[b];           
        }
        
        for(int i = 1; i <= N; ++i)
        {
            if(inOutDegree[i] == N - 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
