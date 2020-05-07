/* https://leetcode.com/problems/majority-element/ */

/* Approach 1: HashMap
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> count;
        
        for(auto &num : nums)
        {
            ++count[num];
            
            if(count[num] > nums.size() / 2) return num;
        }
        
        return -1;
    }
};

/* Approach 2: Sort
Intuition: 假設 majority element 一定存在

Time complexity:  O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() / 2];
    }
};

/* Approach 3: Boyer-Moore Voting Algorithm
Intuition: 

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int candidate = -1;
        
        for(auto &num : nums)
        {
            if(count == 0) candidate = num;
            
            if(num == candidate)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
        
        return candidate;
    }
};
