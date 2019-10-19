/* https://leetcode.com/problems/longest-continuous-increasing-subsequence/ */

/* Approach 1: Sliding Window
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1) return n;
        
        int length = 1;
        
        for(int left = 0, right = 1; right < n; ++right)
        {
            if(nums[right - 1] < nums[right])
            {
                length = max(length, right - left + 1);
            }
            else
            {
                left = right;
            }
        }
        
        return length;
    }
};

/* Approach 2: DP
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1) return n;
        
        int length = 1;
        int dp = 1;
        
        for(int i = 1; i < n; ++i)
        {
            if(nums[i - 1] < nums[i])
            {
               ++dp;
            }
            else
            {
                dp = 1;
            }
            
            length = max(length, dp);
        }
        
        return length;
    }
};
