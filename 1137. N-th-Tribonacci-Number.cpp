/* https://leetcode.com/problems/n-th-tribonacci-number/ */

class Solution {
public:
    int tribonacci(int n) {
        if(n <= 2) return n==0 ? 0: 1;
        
        int tmp, T[3];
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        
        for(int i = 3; i <= n; ++i)
        {
            tmp = T[0] + T[1] + T[2];
            T[0] = T[1];
            T[1] = T[2];
            T[2] = tmp;
        }
        
        return T[2];
    }
};
