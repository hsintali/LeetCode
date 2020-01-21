/* https://leetcode.com/problems/remove-element/ */

/* Approach 1: Two pointer
Intuition: partition 模板

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left = 0; // pointer to val
        int right = nums.size() - 1; // pointer to non-val
        
        while(left <= right)
        {
            // if nums[left] is non-val, move forward
            while(left <= right && nums[left] != val)
            {
                ++left;
            }
            
            // if nums[right] is val, backward
            while(left <= right && nums[right] == val)
            {
                --right;
            }
            
            // remove
            if(left <= right)
            {
                nums[left] = nums[right];
                ++left;
                --right;
            }
        }
        
        return left;
    }
};
