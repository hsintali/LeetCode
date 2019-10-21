/* https://leetcode.com/problems/longest-increasing-subsequence/ */

/* Approach 1: DP
Intuition:

Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1) return n;
        
        int result = 0;
        int f[n];
        
        for(int j = 0; j < n; ++j)
        {
            f[j] = 1;
            
            for(int i = 0; i < j; ++i)
            {
                if(nums[i] < nums[j])
                {
                    f[j] = max(f[j], f[i] + 1);
                }
            }
            
            result = max(result, f[j]);
        }
        
        return result;
    }
};
