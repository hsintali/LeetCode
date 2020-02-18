/* https://leetcode.com/problems/subarray-sum-equals-k/ */

/* Approach 1: two pointers
Intuition: nums 裡面元素有負數的就會失效

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        if(nums.size() == 0) return 0;
        
        int sum = 0;
        int count = 0;
        
        int left = 0;
        
        for(int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            
            while(left < right && sum > k)
            {
                sum -= nums[left++];
            }
            
            if(sum == k)
            {
                ++count;
            }
        }
        
        return count;
    }
};

/* Approach 2: 雙層迴圈
Intuition: 

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        if(nums.size() == 0) return 0;
        
        int count = 0;
               
        for(int left = 0; left < nums.size(); ++left)
        {
            int sum = 0;
            
            for(int right = left; right < nums.size(); ++right)
            {
                sum += nums[right];
                
                if(sum == k)
                {
                    ++count;
                }
            }
        }
        
        return count;
    }
};

/* Approach 3: HashMap
Intuition: 

Time complexity: O(n)
Space complexity: O(n)
*/


