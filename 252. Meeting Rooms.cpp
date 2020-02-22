/* https://leetcode.com/problems/meeting-rooms/ */

/* Approach 1: Greedy + Sort
Intuition:

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[0] < b[0];
             }
        );
        
        int endTime = 0;
        
        for(auto &event : intervals)
        {
            if(event[0] < endTime)
            {
                return false;
            }
            
            endTime = event[1];
        }
        
        return true;
    }
};
