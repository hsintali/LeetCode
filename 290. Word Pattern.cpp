/* https://leetcode.com/problems/word-pattern/ */

/* Approach 1: HashMap
Intuition:
Time complexity:O(P + S)
Space complexity: O(P + S)
*/

class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        vector<string> strs;
        
        size_t start = 0, end = str.find(" ", start);
        while(end != string::npos)
        {
            strs.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find(" ", start);
        }
        strs.push_back(str.substr(start, end));   
        
        if(pattern.size() != strs.size()) return false;
        
        unordered_map<char, string> umap_c2s;
        unordered_map<string, char> umap_s2c;
        
        for(int i = 0; i < pattern.size(); ++i)
        {
            if(umap_c2s.count(pattern[i]) == 0)
            {
                umap_c2s[pattern[i]] = strs[i];
            }
            else if(umap_c2s[pattern[i]] != strs[i])
            {
                return false;
            }
            
            if(umap_s2c.count(strs[i]) == 0)
            {
                umap_s2c[strs[i]] = pattern[i];
            }
            else if(umap_s2c[strs[i]] != pattern[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
