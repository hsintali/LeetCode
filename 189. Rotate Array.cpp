/* https://leetcode.com/problems/rotate-array/ */

/* Approach 1: 三步翻轉法
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1 - k);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0 , nums.size() - 1);
    }
    
    void reverse(vector<int> &A, int start, int end)
    {
        if(start >= end) return;
        
        while(start < end)
        {
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
            ++start;
            --end;
        }
        return;
    }
};
