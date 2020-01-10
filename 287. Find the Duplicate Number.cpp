/* https://leetcode.com/problems/find-the-duplicate-number/ */

/* Approach 1: Binary Search + Pigeonhole Principle (鴿籠原理)
Intuition: 因為 nums 中的元素是從 1~n, nums.size()=n+1，題目說只有一個重複元素。
           透過 binary search 找到 1~n 其中一個數字，計算 <=pivot 的 count，
           如果 count <= pivot，則代表重複的數字在 [1, pivot] 區間，
           反之，則代表重複的數字在 [pivot, n] 區間。

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        // index: 1 ~ n
        int start = 1;
        int end = nums.size() - 1;
        
        while(start + 1 < end)
        {
            int count = 0;
            int mid = start + ((end - start)>>1);
            
            for(auto val : nums)
            {
                if(val <= mid)
                {
                    ++count;
                }
            }
            
            if(count <= mid)
            {
                start = mid;
            }
            else if(count > mid)
            {
                end = mid;
            }
        }
        
        int count = 0;
        for(auto val : nums)
        {
            if(val == end)
            {
                ++count;
            }
        }
        
        return (count > 1) ? end : start;
    }
};
