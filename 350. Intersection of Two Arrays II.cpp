/* https://leetcode.com/problems/intersection-of-two-arrays-ii/ */

/* Approach 1: sort and two pointers
Intuition: 排序之後再逐一比較

Time complexity: O(nlogn + mlogm), n=nums1.size(), m=nums2.size()
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() == 0 || nums2.size() == 0) return vector<int>();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int index1 = 0;
        int index2 = 0;
        
        vector<int> ans;
        
        while(index1 < nums1.size() && index2 < nums2.size())
        {
            if(nums1[index1] == nums2[index2])
            {
                ans.emplace_back(nums1[index1]);
                ++index1;
                ++index2;
            }
            else if (nums1[index1] < nums2[index2])
            {
                ++index1;
            }
            else if (nums1[index1] > nums2[index2])
            {
                ++index2;
            } 
        }
        
        return ans;
    }
};
