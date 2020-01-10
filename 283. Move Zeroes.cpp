/* https://leetcode.com/problems/move-zeroes/ */

/* Approach 1: two pointers (不打亂 nonZero element 的順序)
Intuition: firstZeroPosition 指向前面可存放 nonZero 的位置，i 指向 nonZero 元素的位置，
           將該元素放到 firstZeroPosition 指針的位置之後，++firstZeroPosition。
           放滿所有 nonZero 到前面的位置之後，firstZeroPosition 之後的位置都用填上 0。

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int firstZeroPosition = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                nums[firstZeroPosition++] = nums[i];
            }
        }
        
        for(int i = firstZeroPosition; i < nums.size(); ++i)
        {
            nums[i] = 0;
        } 
    }
};

/* Approach 2: two pointers (可以打亂 nonZero element 的順序)
Intuition: 

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int left = 0; // seek for zero
        int right = nums.size() - 1; // seek for nonZero
        
        while(left < right)
        {
            while(left < right && nums[left] != 0)
            {
                ++left;
            }
            
            while(left < right && nums[right] == 0)
            {
                --right;
            }
            
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }
};
