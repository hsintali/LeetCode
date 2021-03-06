/* https://leetcode.com/problems/maximum-subarray/ */

/* Approach 1: DP (Kadane's Algorithm)
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

// or

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        int curMax = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(maxSum, curMax);
        }       
        return maxSum; 
    }
};

/* Approach 2: PrefixSum
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = INT_MIN;
        int prefixSum_cur = 0;
        int prefixSum_min = 0;
        
        for(auto &num : nums)
        {
            prefixSum_cur += num;
            
            maxSum = max(maxSum, prefixSum_cur - prefixSum_min);

            prefixSum_min = min(prefixSum_min, prefixSum_cur);
        }
        
        return maxSum;
    }
};
