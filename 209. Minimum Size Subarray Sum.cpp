/* https://leetcode.com/problems/minimum-size-subarray-sum/ */

/* Approach 1: two pointer
Intuition:
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        
        int sum = 0;
        int minLen = INT_MAX;
        
        for(int left = 0, right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            
            while(left < right && sum - nums[left] >= s)
            {
                sum -= nums[left++];
            }
            
            if(sum >= s)
            {
                minLen = min(minLen, right - left + 1);
            }
        }
        
        return (minLen == INT_MAX)? 0 : minLen;
    }
};
