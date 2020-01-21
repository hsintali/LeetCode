/* https://leetcode.com/problems/powx-n/ */

/* Approach 1: Mode 2 divide 2 (%2 /2)
Intuition: x^n，其中 n 可用 2 進位表示法: n = 19 = 2^0 + 2^1 + 2^4
           因此，x^n = x^19 = x^1 * x^2 * x^16
           coner case: n 是 INT_MIN 時，轉為正數會 overflow
           
Time complexity: O(log n)
Space complexity: O(1)

class Solution {
public:
    double myPow(double x, int n)
    {
        if(abs(x) < 1e-10) return 0;
        
        long long N = n;
        
        if(N < 0)
        {
            x = 1/x;
            N = -N;
        }
        
        double ans = 1;
        double product = x;

        while(N > 0)
        {
            if(N % 2 == 1)
            {
                ans *= product;
            }
            
            N /= 2;
            product *= product;
        }
        
        return ans;
    }
};
