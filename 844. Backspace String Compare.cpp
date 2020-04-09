/* https://leetcode.com/problems/backspace-string-compare/ */

/* Approach 1: Two Pointers
Intuition:

Time complexity: O(m + n)
Space complexity: O(1)
*/

class Solution {
public:
    bool backspaceCompare(string S, string T)
    {
        int i = S.size() - 1;
        int j = T.size() - 1;
        
        while(i >= 0 || j >= 0)
        {
            int skip_S = 0;
            while(i >= 0 && (S[i] == '#' || skip_S > 0))
            {
                if(S[i] == '#')
                {
                    ++skip_S;
                }
                else
                {
                    --skip_S;
                }
                
                --i;
            }
            
            int skip_T = 0;
            while(j >= 0 && (T[j] == '#' || skip_T > 0))
            {
                if(T[j] == '#')
                {
                    ++skip_T;
                }
                else
                {
                    --skip_T;
                }
                
                --j;
            }
            
            if(i >= 0 && j >= 0 && S[i] != T[j]) return false;
            
            if((i >= 0) != (j >= 0)) return false;
            
            --i;
            --j;
        }
        
        return true;
    }
};
