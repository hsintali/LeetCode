/* https://leetcode.com/problems/single-element-in-a-sorted-array/ */

/* Approach 1: linear search
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i += 2)
        {
            if(nums[i] != nums[i - 1]) return nums[i - 1];
        }
        
        return nums.back();
    }
};

/* Approach 2: binary search
Intuition:

Time complexity:  O(logn)
Space complexity: O(1)
*/

