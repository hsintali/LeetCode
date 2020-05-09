/* https://leetcode.com/problems/valid-perfect-square/ */

/* Approach 1: binary search
Intuition: 與 69. Sqrt(x) 類似。跟平方根有關的問題可用二分法。

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if(num == 1) return true;
        
        long start = 2;
        long end = num / 2;
        
        while(start + 1 < end)
        {
            long long mid = start + ((end - start) >> 1);
            long long product = mid * mid;
            
            if(product == num) return true;
            
            if(product > num)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if(start * start == num || end * end == num) return true;
        
        return false;
    }
};
