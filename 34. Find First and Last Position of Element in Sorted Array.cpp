/* https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ */

/* Approach 1: Brute Force
Intuition:分別找出first, last position

Time complexity: O(n)
Space complexity: O(1)
*/

/* Approach 2: binary search
Intuition:分別找出first, last position

Time complexity: O(log n)
Space complexity: O(1)

Coner case:需要注意當input只有一個的時候
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() < 1) return vector<int>({-1, -1});
        
        int first = helper(nums, target, true);
        if (first == nums.size()) return vector<int>({first, -1});
        
        int last = helper(nums, target, false);
        
        return vector<int>({first, last});
    }
    
    int helper(vector<int>& nums, int target, bool first)
    {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
                    
            if (nums[mid] == target)
            {
                if (first) // find first position
                {
                    end = mid;
                }
                else // find last position
                {
                    start = mid;
                }
            }
            else if (nums[mid] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        if(first) // find first position
        {
            if(nums[start] == target) return start;
            if(nums[end] == target) return end;   
        }
        else // find last position
        {
            if(nums[end] == target) return end;
            if(nums[start] == target) return start;     
        }
        
        return -1;
    }
};
