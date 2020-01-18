/* https://leetcode.com/problems/merge-intervals/ */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ans;
        
        int n = intervals.size();
        if(n == 0) return ans;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<int> cur = intervals[0];
        
        for(int i = 1; i < n; ++i)
        {
            vector<int> next = intervals[i];
            
            if(cur[1] < next[0])
            {
                ans.emplace_back(cur);
                cur = next;
            }
            else
            {
                cur[1] = max(cur[1], next[1]);
            }
        }
        
        ans.emplace_back(cur);
        
        return ans;
    }
    
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
};
