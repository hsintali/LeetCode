/* https://leetcode.com/problems/diagonal-traverse/ */

/* Approach 1:
Intuition: 直接根據題目要求 traverse。
           1. 找出各個方向移動時 index 更新方式，
           2. 判斷該方向是否走到底了，
           3. 更新每個方向的起點 index。
           
Time complexity: O(m*n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        
        int m = matrix.size();
        if(m == 0) return ans;
        
        int n = matrix[0].size();
        if(n == 0) return ans;
        
        bool isDirectionUP = true;      
        int row = 0;
        int col = 0;
        
        while(row < m && col < n)
        {
            ans.push_back(matrix[row][col]);
            
            int nextRow = 0;
            int nextCol = 0;
            
            if(isDirectionUP) // up
            {
                nextRow = row - 1;
                nextCol = col + 1;
            }
            else if(!isDirectionUP) // down
            {
                nextRow = row + 1;
                nextCol = col - 1;
            }
            
            // if the current arrow exceeds matrix, change direction
            if(nextRow < 0 || nextRow == m || nextCol < 0 || nextCol == n)
            {
                isDirectionUP = !isDirectionUP;
                
                if(isDirectionUP) // up
                {
                    if(row + 1 < m)
                    {
                        row += 1;
                    }
                    else
                    {
                        col += 1;
                    }
                }
                else if(!isDirectionUP) // down
                {
                    if(col + 1 < n)
                    {
                        col += 1;
                    }
                    else
                    {
                        row += 1;
                    }
                }
            }
            else // if the current arrow still within the matrix, update indices
            {
                row = nextRow;
                col = nextCol;
            }
        }
        
        return ans;
    }
};
