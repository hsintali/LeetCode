/* https://leetcode.com/problems/number-complement/ */

/* Approach 1:
Intuition: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

Time complexity:  O(1)
Space complexity: O(1)
*/

class Solution {
public:
    int findComplement(int num)
    {
        if(num == 0) return 1;
        
        int bit = 1;
        int numOfBit = log(num) / log(2) + 1;
        
        for(int i = 0; i < numOfBit; ++i)
        {
            num ^= bit;
            bit = bit << 1;
        }
        
        return num;
    }
};
