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
            memo[i][j] = dfs(s, i, p, j + 2, memo) || (isCharMatch(s[i], p[j]) && dfs(s, i + 1, p, j, memo)) ? 1 : -1;
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

/* Approach 2: DP
Intuition:
Time complexity:O(SP)
Space complexity: O(SP)
*/

class Solution {
public:
    bool isMatch(string s, string p)
    {
        if(p.size() == 0) return s.size() == 0;
        
        bool dp[p.size() + 1][s.size() + 1];
        for(int i = 0; i < p.size() + 1; ++i) 
        {
            for(int j = 0; j < s.size() + 1; ++j)
            {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        
        for(int idx_p = 1; idx_p <= p.size(); ++idx_p)
        {
            if(p[idx_p] == '*')
            {
                dp[idx_p + 1][0] = dp[idx_p - 1][0];
                
                for(int idx_s = 1; idx_s <= s.size(); ++idx_s)
                {
                    dp[idx_p + 1][idx_s] = dp[idx_p - 1][idx_s] || (isCharMatch(s[idx_s - 1], p[idx_p - 1]) && dp[idx_p + 1][idx_s - 1]);
                }
                
                ++idx_p;
            }
            else if(p[idx_p - 1] == '.')
            {
                for(int idx_s = 1; idx_s <= s.size(); ++idx_s)
                {
                    dp[idx_p][idx_s] = dp[idx_p - 1][idx_s - 1];
                }
            }
            else
            {
                for(int idx_s = 1; idx_s <= s.size(); ++idx_s)
                {
                    dp[idx_p][idx_s] = dp[idx_p - 1][idx_s - 1] && (p[idx_p - 1] == s[idx_s - 1]);
                }
            }
        }
        
        return dp[p.size()][s.size()];
    }
    
    bool isCharMatch(char s, char p)
    {
        return s == p || p == '.';
    }
};
