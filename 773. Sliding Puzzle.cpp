/* https://leetcode.com/problems/sliding-puzzle/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(R * C * (R*C)!), where R,C are the number of rows and columns in board.
Space complexity: O(R * C * (R*C)!)
*/

class Solution {
public:    
    int slidingPuzzle(vector<vector<int>>& board)
    {
        int n = board.size();
        int m = board[0].size();

        string initState;
        int pos;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                initState += to_string(board[i][j]);
                
                if(board[i][j] == 0)
                {
                    pos = i * m + j;
                }
            }
        }
        
        return BFS(initState, pos);
    }
    
    int BFS(string state, int pos)
    {
        if(state == "123450") return 0;
        
        queue<pair<string, int>> que;
        que.push(make_pair(state, pos));
        visited.insert(state);
        
        vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        
        for(int steps = 1; !que.empty(); ++steps)
        {
            int size = que.size();

            for(int num = 0; num < size; ++num)
            {
                string curState = que.front().first;
                int cur_pos = que.front().second;
                que.pop();
                
                for(auto &move : moves[cur_pos])
                {
                    string newState = curState;
                    char temp = newState[cur_pos];
                    newState[cur_pos] = newState[move];
                    newState[move] = temp;

                    if(newState == "123450") return steps;
                    
                    if(visited.count(newState) == 1) continue;
                    
                    que.push(make_pair(newState, move));
                    visited.insert(newState);
                }
            }
        }
        
        return -1;
    }
    
    unordered_set<string> visited;
};
