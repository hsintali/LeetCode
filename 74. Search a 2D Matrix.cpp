/* https://leetcode.com/problems/search-a-2d-matrix/ */

/* Approach 1: binary search
Intuition:transfer to 1 D and do binary search, where the index of row = idx // n and col = idx % n.

Time complexity: O(log(m*n))
Space complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        if (m == 0) return false;
        
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int start = 0;
        int end = m * n - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(matrix[mid / n][mid % n] == target)
            {
                return true;
            }
            
            if(matrix[mid / n][mid % n] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }

        if (matrix[start / n][start % n] == target || 
            matrix[end / n][end % n] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
