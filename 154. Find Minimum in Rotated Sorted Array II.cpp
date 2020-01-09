/* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/ */

/* Approach 1: binary search
Intuition: 若有重複元素，if(nums[mid] == nums[end]) 時，無法判斷 middle 在左邊還右邊，只好 --end

Time complexity: O(n)
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
            
            if(nums[mid] > nums[end])
            {
                start = mid;
            }
            else if(nums[mid] < nums[end])
            {
                end = mid;
            }
            else if(nums[mid] == nums[end])
            {
                --end;
            }
        }
        
        return nums[start] > nums[end]? nums[end] : nums[start];
    }
};
