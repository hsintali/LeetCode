/* https://leetcode.com/problems/kth-largest-element-in-an-array/ */

/* Approach 1: sort
Intuition:
Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() - k];
    }
};

/* Approach 2: quick selection
Intuition:
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        if(nums.size() == 0) return -1;
        
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
    int quickSelect(vector<int>& nums, int start, int end, int k)
    {
        if(start == end) return nums[start];
        
        int left = start;
        int right = end;
        int pivot = nums[left + ((right - left) >> 1)];
        
        while(left <= right)
        {
            while(left <= right && nums[left] > pivot)
            {
                ++left;
            }
            
            while(left <= right && nums[right] < pivot)
            {
                --right;
            }
            
            if(left <= right)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                ++left;
                --right;
            }
        }
        
        // at here: [start, ..., right, left, ..., end] 
        // or [start, ..., right, some val, left, ..., end] 
        if(start + k - 1 <= right)
        {
            return quickSelect(nums, start, right, k);
        }
        
        if(start + k - 1 >= left)
        {
            return quickSelect(nums, left, end, k - (left - start));
        }
        
        return nums[right + 1];
    }
};

/* Approach 3: min heap sort
Intuition: 將 nums 的數值依序丟掉 heap 中，heap size 保持到最多 k 個，超過則 pop 掉。
           當 nums 的數值都丟到 heap 之後，heap 頂端就會是第 k 大的元素。
           
Time complexity: O(nlogk)
Space complexity: O(k)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(auto val : nums)
        {
            minHeap.push(val);
            
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};
