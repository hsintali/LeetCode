/* https://leetcode.com/problems/word-break/ */

/* Approach 1: DFS
Intuition:

Time complexity:O(n^2)
Space complexity: O(n)
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> dict;
        dict.insert(wordDict.begin(), wordDict.end());
        
        vector<int> memo(s.size(), 0);
        
        return dfs(s, dict, 0, memo);
    }
    
    bool dfs(string &s, unordered_set<string> &dict, int start, vector<int> &memo)
    {
        if(start == s.size()) return true;
        
        if(memo[start] != 0) return memo[start] == 1 ? true : false;
        
        memo[start] = -1;
        
        for(int end = start; end < s.size(); ++end)
        {
            if(dict.find(s.substr(start, end - start + 1)) != dict.end() && dfs(s, dict, end + 1, memo) == true)
            {
                memo[start] = 1;
            }
        }
        
        return memo[start] == 1 ? true : false;
    }
};
