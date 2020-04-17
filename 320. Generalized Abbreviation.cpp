/* https://leetcode.com/problems/generalized-abbreviation/ */

/* Approach 1: DFS
Intuition:

Time complexity:O(n * 2^n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word)
    {
        vector<string> ans;
        dfs(word, "", 0, 0, ans);
        return ans;
    }
    
    void dfs(string &word, string path, int index, int k, vector<string> &ans)
    {
        if(index == word.size())
        {
            string abbr = "";
            if(k > 0) abbr = to_string(k);
            ans.push_back(path + abbr);
            return;
        }
        
        dfs(word, path, index + 1, k + 1, ans);
        
        string abbr = "";
        if(k > 0) abbr = to_string(k);
        dfs(word, path + abbr + word[index], index + 1, 0, ans);
    }
};

/* Approach 1-2: DFS
Intuition:

Time complexity:O(n * 2^n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word)
    {
        vector<string> ans;
        string path;
        dfs(word, path, 0, 0, ans);
        return ans;
    }
    
    void dfs(string &word, string &path, int index, int k, vector<string> &ans)
    {
        if(index == word.size())
        {
            string abbr = "";
            if(k > 0)
            {
                abbr = to_string(k);
                path += abbr;
            }
            
            ans.push_back(path);
            
            if(k > 0)
            {
                for(int i = 0; i < abbr.size(); ++i)
                {
                    path.pop_back();
                }
            }
            
            return;
        }
        
        dfs(word, path, index + 1, k + 1, ans);
        
        
        string abbr = "";
        if(k > 0)
        {
            abbr = to_string(k);
            path += abbr;
        }
        
        path += word[index];
        
        dfs(word, path, index + 1, 0, ans);
        
        path.pop_back();
        
        if(k > 0)
        {
            for(int i = 0; i < abbr.size(); ++i)
            {
                path.pop_back();
            }
        }
    }
};
