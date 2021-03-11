/* https://leetcode.com/problems/reverse-integer/ */

/* Approach 1: Math
Intuition:

Time complexity: O(log x)
Space complexity: O(1)
*/

class Solution {
public:
    int reverse(int x)
    {
        int ans = 0;
        int UPER = INT_MAX / 10;
        int LOWER = INT_MIN / 10;
        while(x)
        {
            if (ans > UPER || ans < LOWER) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
