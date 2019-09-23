/* https://leetcode.com/problems/longest-common-prefix/ */

/* Approach 1: Brute Force
Intuition: Vertical scanning

Time complexity: O(m*n). In the worst case there will be n equal strings with length m.
Space complexity: O(1)
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
