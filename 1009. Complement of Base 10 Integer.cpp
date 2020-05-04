/* https://leetcode.com/problems/complement-of-base-10-integer/ */

/* Approach 1:
Intuition: This question is the same as 476: https://leetcode.com/problems/number-complement/

Time complexity:  O(1)
Space complexity: O(1)
*/

class Solution {
public:
    int bitwiseComplement(int N)
    {
        if(N == 0) return 1;
        
        int bit = 1;
        int numOfBit = log(N) / log(2) + 1;
        
        for(int i = 0; i < numOfBit; ++i)
        {
            N ^= bit;
            bit = bit << 1;
        }
        
        return N;
    }
};
