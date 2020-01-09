/* https://leetcode.com/problems/search-in-rotated-sorted-array-ii/ */

/* Approach 1: binary search
Intuition: 若有重複元素，if(nums[mid] == nums[end]) 時，無法判斷 middle 在左邊還右邊，只好 --end

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        if(nums.size() < 1) return false;
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid] < nums[end]) // middle is on the right side
            {
                if(nums[mid] <= target && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else if(nums[mid] > nums[end]) // middle is on the left side
            {
                if(nums[start] <= target && target <= nums[mid])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
            else if(nums[mid] == nums[end])
            {
                --end;
            }
        }
        
        if(nums[start] == target || nums[end] == target) return true;
        else return false;
    }
};
