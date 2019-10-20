/* https://leetcode.com/problems/single-number/ */

/* Approach 1: Hash
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        set<int> result;
        
        for(int i = 0; i < n; ++i)
        {
            if(result.find(nums[i]) == result.end())
            {
                result.insert(nums[i]);
            }
            else
            {
                result.erase(nums[i]);
            }
        }
        
        return *result.begin();
    }
};

/* Approach 2: XOR
Intuition: a⊕0=a, a⊕a=0, a⊕b⊕a=(a⊕a)⊕b=0⊕b=b

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int result = 0;
        for(int i = 0; i < n; ++i)
        {
            result ^= nums[i];
        }
        
        return result;
    }
};
