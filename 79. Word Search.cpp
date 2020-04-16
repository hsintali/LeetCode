/* https://leetcode.com/problems/word-search/ */

/* Approach 1: DFS
Intuition: 無法使用 BFS，因為 BFS 無法回朔 visited[][]。BFS 無法搜尋圖的路徑，只能搜尋有向圖(樹)的路徑。

Time complexity:O(N * 4^L)
Space complexity: O(L)
*/

class Solution {
public:
    int DIRECTION_X[4] = {1, -1, 0, 0};
    int DIRECTION_Y[4] = {0, 0, 1, -1};
    
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(dfs(board, i, j, word, 0) == true) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y, string &word, int index)
    {
        if(index >= word.size()) return true;
        
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        
        if(board[x][y] != word[index]) return false;
        
        board[x][y] = '#';
        
        for(int i = 0; i < 4; ++i)
        {
            int new_x = x + DIRECTION_X[i];
            int new_y = y + DIRECTION_Y[i];
            
            if(dfs(board, new_x, new_y, word, index + 1) == true) return true;
        }
        
        board[x][y] = word[index];
            
        return false;
    }
};
