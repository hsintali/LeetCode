/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        
        if(digits.size() == 0) return ans;
        
        string letter ;
        
        unordered_map<char, string> umap;
        umap['2'] = "abc";
        umap['3'] = "def";
        umap['4'] = "ghi";
        umap['5'] = "jkl";
        umap['6'] = "mno";
        umap['7'] = "pqrs";
        umap['8'] = "tuv";
        umap['9'] = "wxyz";
        
        dfs(digits, umap, letter, ans);
        
        return ans;
    }
    
    void dfs(string &digits, unordered_map<char, string> &umap, string &letter, vector<string> &ans)
    {
        if(letter.size() == digits.size())
        {
            ans.push_back(letter);
            return;
        }
        
        int digit = digits[letter.size()];
        for(int i = 0; i < umap[digit].size(); ++i)
        {
            letter.push_back(umap[digit][i]);
            dfs(digits, umap, letter, ans);
            letter.pop_back();
        }
    }
};
