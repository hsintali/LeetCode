/* https://leetcode.com/problems/valid-sudoku/ */

/* Approach 1: HashMap + Brute Forece
Intuition:

Time complexity: O(1), 81 cells
Space complexity: O(1), 81 cells
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows[9][9] = {0};   // rows[i][j]: i-th row with number j + 1;
        int cols[9][9] = {0};   // cols[i][j]: i-th col with number j + 1;
        int blocks[9][9] = {0}; // blocks[i][j]: i-th block with number j + 1;
        
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                // i-th row, j-th col
                if(board[i][j] == '.') continue;
                
                int number = board[i][j] - '1';
                int k = i / 3 + (j / 3) * 3;
                
                if(rows[i][number] == 1) return false;
                if(cols[j][number] == 1) return false;
                if(blocks[k][number] == 1) return false;
                
                ++rows[i][number];
                ++cols[j][number];
                ++blocks[k][number];
            }
        }
        
        return true;
    }
};
