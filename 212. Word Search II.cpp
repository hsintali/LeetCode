/* https://leetcode.com/problems/word-search-ii/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    int DIRECTION_X[4] = {1, -1, 0, 0};
    int DIRECTION_Y[4] = {0, 0, 1, -1};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {    
        unordered_set<string> dict;
        unordered_set<string> prefixSet;
        for(auto &word : words)
        {
            dict.insert(word);
            string prefix = "";
            for(auto &c : word)
            {
                prefix += c;
                prefixSet.insert(prefix);
            }
        } 
        
        vector<string> ans;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                string path = {board[i][j]};
                dfs(board, i, j, path, ans, dict, prefixSet);
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>> &board, int x, int y,
             string &path, vector<string> &ans,
             unordered_set<string> &dict, unordered_set<string> &prefixSet)
    {                
        if(dict.count(path) == 1)
        {
            ans.push_back(path);
            dict.erase(path);
        }
        
        board[x][y] = '#';
        
        for(int i = 0; i < 4; ++i)
        {
            int new_x = x + DIRECTION_X[i];
            int new_y = y + DIRECTION_Y[i];
            
            if(new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size()) continue;
            
            if(prefixSet.count(path + board[new_x][new_y]) == 0) continue;
            
            path += board[new_x][new_y];
            dfs(board, new_x, new_y, path, ans, dict, prefixSet);
            path.pop_back();
        }
        
        board[x][y] = path.back();
    }
};
