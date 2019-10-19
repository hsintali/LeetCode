/* https://leetcode.com/problems/decode-ways/ */

/* Approach 2: DP
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        
        int f[3];
        f[0] = 1;
        
        for(int i = 1; i <= n; ++i)
        {
            f[i % 3] = 0;
            
            // last 1 digit -> letter
            if(s[i - 1] != '0')
            {
                f[i % 3] += f[(i - 1) % 3];
            }
            
            // last 2 digits -> letter
            if(i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
            {
                f[i % 3] += f[(i - 2) % 3];
            }
        }
        
        return f[n % 3];    
    }
};
