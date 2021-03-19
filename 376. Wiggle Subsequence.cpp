/* https://leetcode.com/problems/wiggle-subsequence/ */

/* Approach 1: Greedy
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if(nums.size() < 2) return nums.size();
        
        int pre_up = 1, pre_down = 1;
        
        for(int i = 1; i < nums.size(); ++i)
        {
            int diff = nums[i] - nums[i - 1];
            if(diff > 0) pre_up = pre_down + 1;
            if(diff < 0) pre_down = pre_up + 1;
        }
        
        return max(pre_up, pre_down);
    }
};
