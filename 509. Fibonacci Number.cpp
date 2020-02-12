/* https://leetcode.com/problems/fibonacci-number/ */

/* Approach 1: DP
Intuition: 

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int fib(int N)
    {
        if(N < 2) return N;
        
        int f[N + 1];
        
        f[0] = 0;
        f[1] = 1;
        
        for(int i = 2; i <= N; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        
        return f[N];
    }
};
