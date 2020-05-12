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

/* Approach 2: XOR
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int ans = nums[0];
        
        for(int i = 1; i < nums.size(); ++i)
        {
            ans ^= nums[i];
        }
        
        return ans;
    }
};

/* Approach 3: binary search
Intuition:

Time complexity:  O(logn)
Space complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end)
        {
            int mid = start + ((end - start) >> 1);
            
            if (mid % 2 == 1) --mid;
            
            if(nums[mid] == nums[mid + 1])
            {
                start = mid + 2;
  
            }
            else
            {
                end = mid;
            }
        }
                
        return nums[end];
    }
};
