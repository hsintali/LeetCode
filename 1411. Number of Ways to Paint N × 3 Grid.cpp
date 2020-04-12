/* https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ */

/* Approach 1: DP
Intuition:

Time complexity:O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int numOfWays(int n)
    {
        // row with 3 color = 2 * (previous row with 3 color) + 2 * (previous row with 2 color)
        // row with 2 color = 2 * (previous row with 3 color) + 3 * (previous row with 2 color)
        
        long long row_2Color = 6;
        long long row_3Color = 6;
        long long temp_2Color;
        
        for(int i = 2; i <= n; ++i)
        {
            temp_2Color = row_2Color;
            row_2Color = (2 * row_3Color + 3 * row_2Color) % 1000000007;
            row_3Color = (2 * row_3Color + 2 * temp_2Color) % 1000000007;
        }
        
        long long ans = (row_2Color + row_3Color) % 1000000007;
        
        return ans;
    }
};
