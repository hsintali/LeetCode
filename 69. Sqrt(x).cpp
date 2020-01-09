/* https://leetcode.com/problems/sqrtx/ */

/* Approach 1: binary search
Intuition:

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int mySqrt(int x)
    {
        if(x < 2) return x;
        
        long long start = 2;
        long long end = x/2;
        
        while (start + 1 < end)
        {
            long long mid = start + (end - start)/2;
            
            long long val = mid * mid;
            if(val == x)
            {
                return mid;
            }
            else if(val < x)
            {
                start = mid;
            }
            else if(val > x)
            {
                end = mid;
            }
        }
        
        if(end * end <= x) return end;
        else return start;
    }
};
