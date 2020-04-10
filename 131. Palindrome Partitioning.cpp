/* https://leetcode.com/problems/palindrome-partitioning/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> stringList;
        
        dfs(s, stringList, ans);
        
        return ans;
    }
    
    void dfs(string &s, vector<string> &stringList, vector<vector<string>> &ans)
    {
        if(s.size() == 0)
        {
            ans.push_back(stringList);
            return;
        }
        
        for(int i = 1; i <= s.size(); ++i)
        {
            string prefix = s.substr(0, i);
            if(!isPalindrome(prefix)) continue;
            
            string res = s.substr(i, s.size() - i);
            
            stringList.push_back(prefix);
            dfs(res, stringList, ans);
            stringList.pop_back();
        }
    }
    
    bool isPalindrome(string &s)
    {
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end)
        {
            if(s[start++] != s[end--]) return false;
        }
        
        return true;
    }
};
