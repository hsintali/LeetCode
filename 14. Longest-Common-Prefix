/* https://leetcode.com/problems/longest-common-prefix/ */

/* Approach 1: Brute Force
Intuition:

Time complexity:
Space complexity:
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = "";
        
        for(int i = 0; i < strs[0].size(); ++i)
        {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(strs[j][i] != c || strs[j].size() < i)
                    return prefix;
            }
            
            prefix.push_back(c);
        }
        
        return prefix;
    }
};
