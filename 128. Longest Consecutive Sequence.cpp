/* https://leetcode.com/problems/longest-consecutive-sequence/ */

/* Approach 1: hashSet
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> uset;
        
        for(auto num : nums)
        {
            uset.insert(num);
        }
        
        int maxLength = 0;
        for(auto num : nums)
        {
            if(uset.count(num) == 0) continue;
            
            int left = num - 1;
            while(uset.count(left) == 1)
            {
                uset.erase(left);
                --left;
            }
            
            int right = num + 1;
            while(uset.count(right) == 1)
            {
                uset.erase(right);
                ++right;
            }
            
            maxLength = max(maxLength, right - left - 1);
        }
        
        return maxLength;
    }
};
