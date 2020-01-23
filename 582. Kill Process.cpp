/* https://leetcode.com/problems/kill-process/ */

/* Approach 1: BFS + queue
Intuition: 先將各個 process 的 children 存放在 hashMap 中，再透過 BFS 搜尋，找出 kill 的所有子程序。

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        vector<int> ans;
        
        unordered_map<int, vector<int>> hashMap;
        
        for(int i = 0; i < pid.size(); ++i)
        {
            hashMap[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> q;
        
        q.push(kill);
        while(!q.empty())
        {
            vector<int> children = hashMap[q.front()];
            for(auto p : children)
            {
                q.push(p);
            }
            
            ans.push_back(q.front());
            q.pop();
        }
            
        return ans;
    }
};
