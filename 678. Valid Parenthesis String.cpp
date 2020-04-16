/* https://leetcode.com/problems/valid-parenthesis-string/ */

/* Approach 1: Greedy
Intuition:

Time complexity:O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool checkValidString(string s)
    {
        int low = 0, hi = 0;
        
        for(auto &c : s)
        {
            if(c == '(')
            {
                ++low;
                ++hi;
            }
            else if(c == '*')
            {
                --low;
                ++hi;
            }
            else if(c == ')')
            {
                --low;
                --hi;
            }
            
            if(hi < 0) return false;
            low = max(0, low);
        }
        
        return low == 0 ;
    }
};
