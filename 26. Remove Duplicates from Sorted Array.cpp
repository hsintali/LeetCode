/* https://leetcode.com/problems/remove-duplicates-from-sorted-array/ */

/* Approach 1: Two pointer
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        
        int slow = 0; // pointer to unique number
        int fast = 1; // current position
        
        for(; fast < nums.size(); ++fast)
        {
            if(nums[fast] == nums[slow])
            {

            }
            else if(nums[fast] != nums[slow])
            {
                nums[++slow] = nums[fast];
            }
        }
        
        return slow + 1;
    }
};
