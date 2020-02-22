/* https://leetcode.com/problems/meeting-rooms-ii/ */

/* Approach 1: Greedy + Sort + minHeap
Intuition: 用 heap 存放各個房間的結束時間

Time complexity: O(nlogn)
Space complexity: O(n)
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        if(intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[0] < b[0];
             }
        );
        
        // minHeap represent rooms, store the end time of each room
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(0);
                
        for(auto &meeting : intervals)
        {
            if(meeting[0] >= minHeap.top()) // free room available
            {
                minHeap.pop();
                minHeap.push(meeting[1]);
            }
            else if(meeting[0] < minHeap.top()) // free room not available, must allocate a new room 
            {
                minHeap.push(meeting[1]);
            }
        }
        
        return minHeap.size();
    }
};
