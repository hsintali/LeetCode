/* https://leetcode.com/problems/find-peak-element/ */

/* Approach 1: binary search
Intuition:

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if(nums[mid] > nums[mid - 1])
            {
                start = mid;
            }
            else if(nums[mid] < nums[mid - 1])
            {
                end = mid;
            }
        }
        
        return nums[start] > nums[end] ? start : end;
    }
};
