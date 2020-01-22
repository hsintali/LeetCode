/* https://leetcode.com/problems/subarray-product-less-than-k/ *

/* Approach 1: two pointer + sliding window
Intuition:跳過所有 product >= k 的情況，此時的 left, right 組成的區間會滿足 product < k。

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(nums.size() == 0) return 0;
        
        int product = 1;
        int count = 0;

        for(int left = 0, right = 0; right < nums.size(); ++right)
        {
            product *= nums[right];
            
            while(left < right && product >= k)
            {
                product /= nums[left++];
            }
            
            if(product < k)
            {
                count += right - left + 1;
            }
        }
        
        return count;
    }
};
