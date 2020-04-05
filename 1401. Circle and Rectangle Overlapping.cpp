/* https://leetcode.com/problems/circle-and-rectangle-overlapping/ */

/* Approach 1:
Intuition:

Time complexity: O(1)
Space complexity: O(1)
*/

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        int x = x_center;
        if(x_center > x2) x = x2;
        if(x_center < x1) x = x1;
        
        int y = y_center;
        if(y_center > y2) y = y2;
        if(y_center < y1) y = y1;
        
        return (x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) <= radius * radius;
    }
};
