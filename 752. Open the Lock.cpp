/* https://leetcode.com/problems/open-the-lock/ */

/* Approach 1: BFS
Intuition: 

Time complexity: O(N^2 * A^N + D):
                 where A is the number of digits in our alphabet,
                 N is the number of digits in the lock,
                 and D is the size of deadends.
                 1. N^2 for enumerating through and constructing lock.
                 2. A^N for total possible lock
                 3. D for instantiating deads set
                 
Space complexity: O(A^N + D)
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> deads;
        unordered_set<string> visited;
        queue<string> que;
        
        for(auto &dead : deadends)
        {
            deads.insert(dead);
        }
        
        if(deads.count("0000") == 1) return -1;
        
        que.push("0000");
        visited.insert("0000");
        
        vector<int> directions = {-1, 1}; 
        
        for(int count = 1; !que.empty(); ++count)
        {
            int size = que.size();
            for(int num = 0; num < size; ++num)
            {
                string cur = que.front();
                que.pop();
                
                for(int i = 0; i < 4; ++i)
                {
                    for(auto dir : directions)
                    {
                        string next = cur.substr(0, i) + to_string(((cur[i] - '0') + 10 + dir) % 10) + cur.substr(i + 1);
                        
                        if(next == target) return count;
                        
                        if(deads.count(next) == 1 || visited.count(next) == 1) continue;
                        
                        que.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        
        return -1;
    }
};

/* Approach 1-2: BFS (Speedup)
Intuition: 

Time complexity: O(N^2 * A^N + D):
                 where A is the number of digits in our alphabet,
                 N is the number of digits in the lock,
                 and D is the size of deadends.
                 1. N^2 for enumerating through and constructing lock.
                 2. A^N for total possible lock
                 3. D for instantiating deads set
                 
Space complexity: O(A^N + D)
*/

class Solution {
public:  
    int openLock(vector<string>& deadends, string target)
    {
        bool deads[10000] = {false};
        bool visited[10000] = {false};
        queue<string> que;
        
        for(auto &dead : deadends)
        {
            deads[stoi(dead)] = true;
        }
        
        if(deads[stoi("0000")] == true) return -1;
        
        que.push("0000");
        visited[stoi("0000")] = true;
        
        vector<int> directions = {-1, 1}; 
        
        for(int count = 1; !que.empty(); ++count)
        {
            int size = que.size();
            for(int num = 0; num < size; ++num)
            {
                string cur = que.front();
                que.pop();
                
                for(int i = 0; i < 4; ++i)
                {
                    // next[i] - 1
                    {
                        string next = cur;
                        
                        next[i] = next[i] == '0' ? '9' : '0' + (next[i] - '0' - 1);
                        
                        if(next == target) return count;
                        
                        if(deads[stoi(next)] != true && visited[stoi(next)] != true) 
                        {
                            que.push(next);
                            visited[stoi(next)] = true;
                        }
                    }
                    
                    // next[i] + 1
                    {
                        string next = cur;
                        
                        next[i] = next[i] == '9' ? '0' : '0' + (next[i] - '0' + 1);
                        
                        if(next == target) return count;
                        
                        if(deads[stoi(next)] != true && visited[stoi(next)] != true) 
                        {
                            que.push(next);
                            visited[stoi(next)] = true;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
