/* https://leetcode.com/problems/wildcard-matching/ */

/* Approach 1: DFS (TLE)
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    bool isMatch(string s, string p)
    {
        return dfs(s, 0, p, 0);
    }
    
    bool dfs(string &s, int i, string &p, int j)
    {
        // s[i:] is empty, the remaining of p must be '*'
        if(i == s.size())
        {
            while(j < p.size())
            {
                if(p[j++] != '*') return false;
            }
            
            return true;
        }
        
        // p[j:] is empty
        if(j == p.size()) return false;
        
        // s[i:], p[j:] are non-empty
        if(p[j] == '*')
        {
            return dfs(s, i + 1, p, j) || dfs(s, i, p, j + 1);
        }
        else
        {
            if(isCharMatch(s[i], p[j]) == true)
            {
                return dfs(s, i + 1, p, j + 1);
            }
            else
            {
                return false;
            }
        }
    }
    
    bool isCharMatch(char &s, char &p)
    {
        if(s == p || p == '?') return true;     
        return false;
    }
};

/* Approach 2: DFS + memorization
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
        if(memo[i][j] != 0) return memo[i][j] == 1 ? true : false;
        
        // s[i:] is empty, the remaining of p must be '*'
        if(i == s.size())
        {
            while(j < p.size())
            {
                if(p[j++] != '*') return false;
            }
            
            return true;
        }
        
        // p[j:] is empty
        if(j == p.size()) return false;
        
        // s[i:], p[j:] are non-empty
        if(p[j] == '*')
        {
            memo[i][j] = dfs(s, i + 1, p, j, memo) || dfs(s, i, p, j + 1, memo) ? 1 : -1;
        }
        else if(p[j] != '*' && isCharMatch(s[i], p[j]) == true)
        {
            memo[i][j] = dfs(s, i + 1, p, j + 1, memo) ? 1 : -1;
        }
        
        return memo[i][j] == 1 ? true : false;
    }
    
    bool isCharMatch(char &s, char &p)
    {
        if(s == p || p == '?') return true;     
        return false;
    }
};


/* Approach 4: Backtrack
Intuition:

Time complexity:O()
Space complexity: O(1)
*/

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int i = 0, j = 0;
        int s_temp_idx = -1;
        int p_star_idx = -1;
        
        while(i < s.size())
        {
            if(j < p.size() && (s[i] == p[j] || p[j] == '?'))
            {
                ++i;
                ++j;
            }
            else if(j < p.size() && p[j] == '*')
            {
                s_temp_idx = i;
                
                p_star_idx = j;
                ++j;
            }
            else if(p_star_idx >= 0) // backtrack
            {
                i = s_temp_idx + 1;
                s_temp_idx = i;
                
                j = p_star_idx + 1;
            }
            else
            {
                return false;
            }
        }
        
        while(j < p.size())
        {
            if(p[j++] != '*') return false;
        }
        
        return true;
    } 
};
