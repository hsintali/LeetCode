/* https://leetcode.com/problems/median-of-two-sorted-arrays/ */

/* Approach 2:
Intuition: 直接排序後選出中位數。

Time complexity:O( (n + m) * log(n + m) )
Space complexity: O(abs(m-n))
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        if(nums1.size() % 2 == 0)
        {
            double mid = (double)nums1[nums1.size() / 2] + (double)nums1[nums1.size() / 2 - 1];
            return mid / 2;
        }
        
        return nums1[nums1.size() / 2];
    }
};

/* Approach 2:
Intuition: 使用 (88. Merge Sorted Array) 的方法 merge nums2 到 nums1 (合併後會是 sorted)，然後再直接選中位數。

Time complexity:O(n + m)
Space complexity: O(abs(m-n))
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {        
        int i1 = nums1.size() - 1;
        int i2 = nums2.size() - 1;
        
        nums1.resize(nums1.size() + nums2.size());
        int p = nums1.size() - 1;
        
        while(i1 >= 0 && i2 >= 0)
        {
            if(nums1[i1] < nums2[i2])
            {
                nums1[p--] = nums2[i2--];
            }
            else
            {
                nums1[p--] = nums1[i1--];
            }
        }
        
        while(i2 >= 0)
        {
            nums1[p--] = nums2[i2--];
        }
        
        if(nums1.size() % 2 == 0)
        {
            double mid = (double)nums1[nums1.size() / 2] + (double)nums1[nums1.size() / 2 - 1];
            return mid / 2;
        }
        
        return nums1[nums1.size() / 2];
    }
};
