/* https://leetcode.com/problems/rotate-image/ */

/* Approach 1:
Intuition: 向右轉90度:轉置後再 reverse column
           向左轉90度:轉置後再 reverse row

Time complexity:  O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = i; j < matrix.size(); ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
