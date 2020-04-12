/* https://leetcode.com/problems/regular-expression-matching/ */

/* Approach 1: DFS + memorization
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, 0));
        
        return dfs(s, 0, p, 0, memo);
    }
    
    bool dfs(string &s, int i, string &p, int j, vector<vector<int>> &memo)
    {
        if(memo[i][j] != 0) return memo[i][j] == 1;
        
        // if s[i:] is empty, p{[j:] must be ".*"
        if(i == s.size())
        {
            while(j + 1 < p.size())
            {
                if(p[j + 1] != '*') return false;
                j += 2;
            }
            
            if(j == p.size() - 1) return false;
            
            return true;
        }
        
        // if p[j:] is empty
        if(j == p.size()) return false;
        
        if(j < p.size() - 1 && p[j + 1] == '*')
        {
            memo[i][j] = dfs(s, i, p, j + 2, memo) || (isCharMatch(s[i], p[j]) && dfs(s, i + 1, p, j, memo));
        }
        else if(isCharMatch(s[i], p[j]))
        {
            memo[i][j] = dfs(s, i + 1, p, j + 1, memo) ? 1 : -1;
        }
        
        return memo[i][j] == 1;
    }
    
    bool isCharMatch(char s, char p)
    {
        return s == p || p == '.';
    }
};
