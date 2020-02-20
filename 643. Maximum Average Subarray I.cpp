/* https://leetcode.com/problems/maximum-average-subarray-i/ */

/* Approach 1: Sliding Window
Intuition:
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double sum = 0;
        
        for(int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }
        
        double ans = sum;
        
        for(int i = k; i < nums.size(); ++i)
        {
            sum += nums[i] - nums[i - k];
            
            ans = max(ans, sum);
        }
        
        return ans/k;
    }
};
