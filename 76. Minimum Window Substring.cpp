/* https://leetcode.com/problems/minimum-window-substring/ */

/* Approach 1: Hash + Sliding Window
Intuition:

Time complexity:  O(S + T)
Space complexity: O(S + T)
*/

class Solution {
public:
    string minWindow(string s, string t)
    {
        if(s.size() < t.size()) return "";
        
        int S = 0; // number of unique char in selected s
        unordered_map<char, int> umapS; 
        
        int T = 0; // number of unique char in t
        unordered_map<char, int> umapT;
        for(auto &c : t)
        {
            if(umapT.count(c) == 0)
            {
                ++T;
            }
            ++umapT[c];
        }
        
        string ans = "";
        int ansL = -1, ansR = -1;
        int left = 0, right = 0;
        for(left = 0; left < s.size(); ++left)
        {
            for( ; right < s.size() && S < T; ++right)
            {
                char c = s[right];
                if(umapT.count(c) == 1)
                {
                    ++umapS[c];
                    if(umapS[c] == umapT[c]) ++S;
                }
            }
            
            if(S == T && (ansL == -1 || right - left < ansR - ansL))
            {
                ansL = left;
                ansR = right;
            }
            
            --umapS[s[left]];
            if(umapT.count(s[left]) == 1 && umapS[s[left]] == umapT[s[left]] - 1)
            {
                --S;
            }
        }
        
        if(ansL == -1) return "";
        
        return s.substr(ansL, ansR - ansL);
    }
};
