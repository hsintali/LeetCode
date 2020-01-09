/* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ */

/* Approach 1: binary search
Intuition: nums[mid] 必須去比較nums[nums.size() - 1]
           因為 [1, 2, 3, 4, 5] 也是 rotated sorted array
           若用 nums[0] 比較，則會有問題

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] >= nums[nums.size() - 1])
            {
                start = mid;
            }
            else if(nums[mid] < nums[nums.size() - 1])
            {
                end = mid;
            }
        }
        
        return nums[start] > nums[end]? nums[end] : nums[start];
    }
};
