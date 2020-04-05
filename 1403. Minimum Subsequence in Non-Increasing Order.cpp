/* https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/ */

/* Approach 1: Sort
Intuition:

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums)
    {
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        
        int totalSum = 0;
        for(auto &a : nums)
        {
            totalSum += a;
        }
        
        int sum = 0;
        totalSum /= 2;
        while(sum <= totalSum)
        {
            sum += nums.back();     
            ans.push_back(nums.back());
            nums.pop_back();
        }
        
        return ans;
    }
};
