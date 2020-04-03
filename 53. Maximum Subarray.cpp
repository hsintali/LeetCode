/* https://leetcode.com/problems/maximum-subarray/ */

/* Approach 1: DP
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        
        for(int i = 1; i < nums.size(); ++i)
        {
            nums[i] += (nums[i - 1] > 0) ? nums[i - 1] : 0;
            maxSum = max(maxSum, nums[i]);
        }
        
        return maxSum;
    }
};
