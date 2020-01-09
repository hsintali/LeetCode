/* https://leetcode.com/problems/search-a-2d-matrix-ii/ */

/* Approach 1: binary search

Intuition:以矩陣右上角元素做為pivot:
          if (target > pivot) ++colIndex;
          if (target < pivot) --rowIndex;

Time complexity: O(n+m)
Space complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        
        int x = matrix[0].size() - 1;
        int y = 0;
        
        while(x >= 0 && y < matrix.size())
        {
            if (matrix[y][x] == target)
            {
                return true;
            }
            
            if (matrix[y][x] < target)
            {
                ++y;
            }
            else
            {
                --x;
            }
        }
        
        return false;
    }
};
