/* https://leetcode.com/problems/backspace-string-compare/ */

/* Approach 1: Stack
Intuition:

Time complexity: O(m + n)
Space complexity: O(m + n)
*/

class Solution {
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> stk_S, stk_T;
        
        for(auto &c : S)
        {
            if(c != '#')
            {
                stk_S.push(c);
            }
            else if(!stk_S.empty())
            {
                stk_S.pop();
            }
        }
        
        for(auto &c : T)
        {
            if(c != '#')
            {
                stk_T.push(c);
            }
            else if(!stk_T.empty())
            {
                stk_T.pop();
            }
        }
        
        if(stk_S.size() != stk_T.size()) return false;
        
        while(!stk_S.empty())
        {
            if(stk_S.top() != stk_T.top()) return false;
            stk_S.pop();
            stk_T.pop();
        }
        
        return true;
    }
};

/* Approach 2: Two Pointers
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
