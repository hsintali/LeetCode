/* https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/ */

/* Approach 1: Hash
Intuition: 因為 0 <= nums[i] <= 100，所以可以去計算每個數字出現的次數。進而計算小於某數的次數。

Time complexity: O(n)
Space complexity: O(102)
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        vector<int> ans;
        
        if(nums.size() == 0) return ans;
        
        vector<int> count(102, 0);
        
        for(auto & num : nums)
        {
            ++count[num + 1];
        }
        
        for(int i = 1; i < count.size(); ++i)
        {
            count[i] += count[i - 1];
        }
        
        for(auto & num : nums)
        {
            ans.push_back(count[num]);
        }
        
        return ans;
    }
};
