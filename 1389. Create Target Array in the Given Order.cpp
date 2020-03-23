/* https://leetcode.com/problems/create-target-array-in-the-given-order/ */

/* Approach 1:
Intuition:

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
    {
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        
        return ans;
    }
};
