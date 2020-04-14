/* https://leetcode.com/problems/n-queens/ */

/* Approach 1: DFS
Intuition:

Time complexity:O(n!)
Space complexity: O(n)
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<int> position; // the position of queen at each row
        
        dfs(n, 0, position, ans);
        
        return ans;
    }
    
    void dfs(int n, int row, vector<int> &position, vector<vector<string>> &ans)
    {
        if(position.size() == n)
        {
            ans.push_back(drawResult(position));
            return;
        }
        
        for(int col = 0; col < n; ++col)
        {
            if(isValid(row, col, position) == false) continue;
            
            position.push_back(col);
            dfs(n, row + 1, position, ans);
            position.pop_back();
        }
    }
    
    bool isValid(int row, int col, vector<int> &position)
    {
        for(int r = 0; r < position.size(); ++r)
        {
            int c = position[r];
            
            if(col == c) return false;
            if(row - r == col - c) return false;
            if(row - r == -(col - c)) return false;
        }
        
        return true;
    }
    
    vector<string> drawResult(vector<int> &position)
    {
        vector<string> res;
        
        for(int r = 0; r < position.size(); ++r)
        {
            int c = position[r];
            string oneRow;
            
            for(int i = 0; i < position.size(); ++i)
            {
                if(i == c)
                {
                    oneRow += "Q";
                }
                else
                {
                    oneRow +=".";
                }
            }
            
            res.push_back(oneRow);
        }
        
        return res;
    }
};
