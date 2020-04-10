/* https://leetcode.com/problems/palindrome-partitioning-ii/ */

/* Approach 1: BFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    int minCut(string s)
    {
        vector<bool> visited(s.size(), false);
        
        return bfs(s, visited);;
    }

    int bfs(string &s, vector<bool> &visited)
    {
        queue<pair<int,int>> que;
        que.push(make_pair(0, s.size() - 1));
        
        int count = -1;
        
        while(!que.empty())
        {
            ++count;
            
            int size = que.size();
            for(int item = 0; item < size; ++item)
            {
                int start = que.front().first;
                int end = que.front().second;
                que.pop();
                
                if(start > end) continue;
                
                for(int i = start; i <= end; ++i)
                {
                    if(visited[i] == true) continue;
                    
                    // prefix: s[start:i]
                    if(!isPalindrome(s, start, i)) continue;
                                        
                    if(i == end)
                    {
                        return count;
                    }
                    
                    // res: s[i + 1:end]
                    que.push(make_pair(i + 1, end));
                    
                    visited[i] = true;
                }
            }
        }
        
        return count;
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while(start < end)
        {
            if(s[start++] != s[end--]) return false;
        }

        return true;
    }
};
