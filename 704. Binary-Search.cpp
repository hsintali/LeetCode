/* https://leetcode.com/problems/binary-search/ */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left + 1 < right)
        {
            int mid = left + (right - left)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(target < nums[mid])
                right = mid;
            else
                left = mid;
        }
        
        if(nums[left] == target)
            return left;
        else if(nums[right] == target)
            return right;
        else
            return -1;
    }
};
