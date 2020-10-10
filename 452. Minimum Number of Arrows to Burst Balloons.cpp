/* https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/ */

/* Approach 1: Sort + Greedy
Intuition: 類似 56. Merge Intervals
                1288. Remove Covered Intervals
Time complexity:  O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if(points.size() == 0) return 0;
        
        sort(points.begin(), points.end(), [](vector<int> &v1, vector<int> &v2)
             {
                 return v1[0] == v2[0] ? v1[1] <= v2[1] : v1[0] < v2[0];
             });
        
        int count = points.size();
        vector<int> cur = points[0];

        for(int i = 1; i < points.size(); ++i)
        {
            vector<int> next = points[i];

            if(next[0] <= cur[1])
            {
                --count;
                cur[0] = max(cur[0], next[0]);
                cur[1] = min(cur[1], next[1]);
            }
            else
            {
                cur = next;
            }
        }

        return count;
    }
};
