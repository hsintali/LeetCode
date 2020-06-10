/* https://leetcode.com/problems/search-insert-position/ */

/* Approach 1: Binary Search
Intuition:

Time complexity:  O(logn)
Space complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size();
        
        while(start + 1 < end)
        {
            int mid = start + ((end - start) >> 1);
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                end = mid;
            }
            else if(nums[mid] < target)
            {
                start = mid;
            }
        }
        
        if(nums[start] >= target) return start;
        return end;
    }
};
