/* https://leetcode.com/problems/sort-colors/ */

/* Approach 1: Two pointer + 1 pointer (one-pass)
Intuition: 左指針指向可以放置0的位置，右指針指向可以放置2的位置，curr指針從左往右遍歷。
           需要注意，while(curr <= right) 要用 <= 而不是 < ，
           因為 curr == right 時，此位置的值還未被處理過。

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int left = 0; // pointer to 0
        int right = nums.size() - 1; // pointer to 2
        int curr = 0; // pointer to current position
        
        while(curr <= right)
        {
            if(nums[curr] == 0)
            {
                int temp = nums[curr];
                nums[curr++] = nums[left];
                nums[left++] = temp;
            }
            else if(nums[curr] == 2)
            {
                int temp = nums[curr];
                nums[curr] = nums[right];
                nums[right--] = temp; 
            }
            else
            {
                ++curr;
            }
        }
    }
};
