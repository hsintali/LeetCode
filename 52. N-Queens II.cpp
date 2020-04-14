/* https://leetcode.com/problems/n-queens-ii/ */

/* Approach 1: DFS
Intuition:
Time complexity:O(n!)
Space complexity: O(n)
*/

class Solution {
public:
    int totalNQueens(int n)
    {
        int ans = 0;
        vector<int> position; // the position of queen at each row
        
        dfs(n, 0, position, ans);
        
        return ans;
    }
    
    void dfs(int n, int row, vector<int> &position, int &ans)
    {
        if(position.size() == n)
        {
            ++ans;
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
};
