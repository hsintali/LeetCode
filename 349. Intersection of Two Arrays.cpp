/* https://leetcode.com/problems/intersection-of-two-arrays/ */

/* Approach 1: sort + binary search
Intuition: 先對 nums2 排序，然後遍歷 nums1 各個元素查找 nums2 是否存在，若存在則存到 set 中。

Time complexity: O( nlog(m) + mlog(m) ) = O( (n+m)log(m) ), n=nums1.size(), m=nums2.size()
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() == 0 || nums2.size() == 0) return vector<int>();
        
        vector<int> ans;
        unordered_set<int> set;
        
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            if(binarySearch(nums2, nums1[i]))
            {
                set.insert(nums1[i]);
            }
        }
        
        for(auto it = set.begin(); it != set.end(); ++it)
        {
            ans.push_back(*it);
        }
        
        return ans;
    }
    
    bool binarySearch(vector<int> &A, int target)
    {
        int start = 0;
        int end = A.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(A[mid] == target)
            {
                return true;
            }
            else if(A[mid] > target)
            {
                end = mid;
            }
            else if(A[mid] < target)
            {
                start = mid;
            }
        }
        
        if(A[start] == target || A[end] == target)
        {
            return true;
        }
        
        return false;
    } 
};

/* Approach 2: two set
Intuition: 將 nums1. nums2 存到 set1, set2，再遍歷 set1，判斷 set2 中是否存在相同元素
Time complexity: O(n+m), n=nums1.size(), m=nums2.size()
Space complexity: O(n+m)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() == 0 || nums2.size() == 0) return vector<int>();
        
        unordered_set<int> set1, set2;
        
        for(auto val : nums1)
        {
            set1.emplace(val);
        }
        
        for(auto val : nums2)
        {
            set2.emplace(val);
        }
        
        vector<int> ans;
        
        for(auto val : set1)
        {
            if(set2.find(val) != set2.end())
            {
                ans.emplace_back(val);
            }
        }
        
        return ans;
    }
};
