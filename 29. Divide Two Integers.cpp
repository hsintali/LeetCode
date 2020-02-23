/* https://leetcode.com/problems/divide-two-integers/ */

/* Approach 1: Math
Intuition: 商數(quotient)，就是 被除數(dividend) 可以被 除數(divisor) 減去的次數(倍數)。
           所以當 dividend - (divisor << x) >= 0，則表示其 quotient 至少有 (1 << x) ==> quotient += (1 << x)

Time complexity: O(32) = O(1)
Space complexity: O(1)
*/

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        // coner case: 因為回傳型態是 int 所以只能回傳 INT_MAX
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // a = bq + r
        long  a = labs(dividend);
        long  b = labs(divisor);   
        long  q = 0;
        
        for(long  x = 31; x >= 0; --x)
        {
            if(a - (b << x) >= 0)
            {
                q += 1L << x;
                a -= b << x;
            }
        }

        return ((dividend > 0) == (divisor > 0)) ? q : -q;
    }
};
