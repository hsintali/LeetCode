/* https://leetcode.com/problems/increasing-triplet-subsequence/ */

/* Approach 1:
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        if(nums.size() < 3) return false;
        
        int firstElem = nums[0];
        int secondElem = INT_MAX;
        
        for(size_t i = 1; i < nums.size(); ++i)
        {
            if(firstElem < nums[i]) // nums[i] may be the 2nd element or 3rd element
            {
                if(secondElem < nums[i]) // nums[i] is the 3rd element
                {
                    return true;
                }
                else
                {
                    // set secondElem 
                    secondElem = min(secondElem, nums[i]);
                }
            }
            else
            {
                // set firstElem 
                firstElem = nums[i];
            }
        }
        
        return false;
    }
};
