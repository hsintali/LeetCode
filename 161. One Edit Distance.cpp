/* https://leetcode.com/problems/one-edit-distance/ */

/* Approach 1:
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if (m < n)
        {
            return isOneEditDistance(t, s);
        }
        
        if(m - n > 1) return false;
        
        for(int i = 0; i < m; ++i)
        {
            if(s[i] != t[i])
            {
                if(m == n)
                {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else
                {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
        }
        
        return false;
    }
};
