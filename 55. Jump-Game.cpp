/* https://leetcode.com/problems/jump-game/ */

/* Approach 1: DP
Intuition:
Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return false;
        
        bool f[n];       
        f[0] = true;
        
        for(int i = 1; i < n; ++i)
        {
            f[i] = false;
            
            for(int j = 0; j < i; ++j)
            {
                if(f[j] == true && j + nums[j] >= i)
                {
                    f[i] = true;
                    break;
                }
            }
        }
        
        return f[n - 1];
    }
};
