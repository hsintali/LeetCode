/* https://leetcode.com/problems/check-if-it-is-a-straight-line/ */

/* Approach 1:
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if(coordinates.size() <= 2) return true;
        
        int slop_x = coordinates[1][0] - coordinates[0][0];
        int slop_y = coordinates[1][1] - coordinates[0][1];
        
        for(int i = 2; i < coordinates.size(); ++i)
        {
            int delta_x = coordinates[i][0] - coordinates[i - 1][0];
            int delta_y = coordinates[i][1] - coordinates[i - 1][1];
            
            if(slop_x * delta_y != slop_y * delta_x) return false;
        }
        
        return true;
    }
};
