/* https://leetcode.com/problems/search-in-rotated-sorted-array/ */

/* Approach 1: binary search
Intuition: 每次都先判斷nums[mid]在左邊或右邊，
           若在左邊，則去判斷 target 是否在 start~mid 區間，
           若在右邊，則去判斷 target 是否在 mid~end 區間。

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if(nums.size() < 1) return -1;
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] <= nums[end]) // middle is on the right side
            {
                if(nums[mid] <= target && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else if(nums[mid] > nums[end]) // middle is on the left side
            {
                if(nums[start] <= target && target <= nums[mid])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
        }
        
        if(nums[start] == target) return start;
        else if(nums[end] == target) return end;
        else return -1;
    }
};

/* Approach 2: hashmap
Intuition: 將 nums2 存到hashmap 並存放各元素出現次數，
           遍歷 nums1 去查找 hashmap。

Time complexity: O(n+m)
Space complexity: O(min(n,m))
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n < m)
        {
            return intersect(nums2, nums1);
        }
        
        if(n == 0 || m == 0) return vector<int>();
        
        unordered_map<int, int> hashMap;
        vector<int> ans;
        
        for(auto val : nums2)
        {
            if(hashMap.find(val) != hashMap.end())
            {
                ++hashMap[val];
            }
            else
            {
                hashMap[val] = 1;
            }
        }
        
        for(auto val : nums1)
        {
            if(hashMap.find(val) != hashMap.end() && hashMap[val] > 0)
            {
                ans.emplace_back(val);
                --hashMap[val];
            }
        }

        return ans;
    }
};
