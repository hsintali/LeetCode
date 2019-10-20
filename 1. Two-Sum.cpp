/* https://leetcode.com/problems/two-sum/ */

/* Approach 1: two pointer
Intuition:

Time complexity: O(nlogn)
Space complexity: O(n)
*/

/* Approach 2: hash table
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(n <= 1) return vector<int>();
        
        unordered_map<int, int> hash;
        vector<int> result;
        
        for(int i = 0; i < n; ++i)
        {
            int diff = target - nums[i];
            
            if(hash.find(diff) != hash.end())
            {
                result.push_back(hash[diff]);
                result.push_back(i);
                return result;
            }
            else
            {
                hash[nums[i]] = i;
            }
        }
        
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};
