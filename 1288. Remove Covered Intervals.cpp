/* https://leetcode.com/problems/remove-covered-intervals/ */

/* Approach 1: Sort + Greedy
Intuition: 類似 merge intervals

Time complexity:  O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2)
             {
                 return v1[0] == v2[0] ? v1[1] >= v2[1] : v1[0] <= v2[0];
             });
        
        int count = intervals.size();
        vector<int> cur = intervals[0];
        
        for(int i = 1; i < intervals.size(); ++i)
        {
            vector<int> next = intervals[i];
            
            if(next[1] <= cur[1])
            {
                --count;
            }
            else
            {
                cur = next;
            }
        }
        
        return count;
    }
};
