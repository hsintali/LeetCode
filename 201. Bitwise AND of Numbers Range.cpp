/* https://leetcode.com/problems/bitwise-and-of-numbers-range/ */

/* Approach 1: bits
Intuition:

Time complexity:  O(1)
Space complexity: O(1)
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        while(m < n)
        {
            n &= n - 1;
        }
        
        return n & m;
    }
};
