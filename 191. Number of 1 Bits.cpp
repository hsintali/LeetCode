/* https://leetcode.com/problems/number-of-1-bits/ */

/* Approach 1:
Intuition:

Time complexity:  O()
Space complexity: O()
*/

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int count{};
        
        while(n > 0)
        {
            n &= n - 1;
            ++count;
        }
        
        return count;
    }
};
