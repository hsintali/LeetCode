/* https://leetcode.com/problems/search-in-rotated-sorted-array/ */

/* Approach 1: binary search
Intuition: 每次都先判斷nums[mid]在左邊或右邊，
           若在左邊，則去判斷 target 是否在 start~mid 區間，
           若在右邊，則去判斷 target 是否在 mid~end 區間。

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if(nums.size() < 1) return -1;
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] <= nums[nums.size() - 1]) // middle is on the right side
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
            else if(nums[mid] > nums[nums.size() - 1]) // middle is on the left side
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
        }
        
        if(nums[start] == target) return start;
        else if(nums[end] == target) return end;
        else return -1;
    }
};
