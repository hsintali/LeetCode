/* https://leetcode.com/problems/surrounded-regions/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(m * n)
Space complexity: O(m * n)
*/

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        if(board.size() == 0 || board[0].size() == 0) return;
        
        int n = board.size();
        int m = board[0].size();
        
        queue<pair<int, int>> que;
        
        for(int i = 0; i < n; ++i)
        {
            if(board[i][0] == 'O')
            {
                que.push(make_pair(i, 0));
            }
            
            if(board[i][m - 1] == 'O')
            {
                que.push(make_pair(i, m - 1));
            }
        }
        
        for(int j = 0; j < m; ++j)
        {
            if(board[0][j] == 'O')
            {
                que.push(make_pair(0, j));
            }
            
            if(board[n - 1][j] == 'O')
            {
                que.push(make_pair(n - 1, j));
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!que.empty())
        {
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            que.pop();
            
            board[cur_x][cur_y] = 'V';
            
            for(int i = 0; i < 4; ++i)
            {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];
                
                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
                
                if(board[new_x][new_y] == 'O')
                {
                    que.push(make_pair(new_x, new_y));
                    board[new_x][new_y] = 'V';
                }
            }
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(board[i][j] == 'V')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }  
    }
};
