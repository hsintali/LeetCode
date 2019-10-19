/* https://leetcode.com/problems/counting-bits/ */

/* Approach 1: DP
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> f(num + 1, 0);

        for(int i = 1; i <= num; ++i)
        {
            f[i] = f[i >> 1] + i % 2;
        }
        
        return f;
    }
};
