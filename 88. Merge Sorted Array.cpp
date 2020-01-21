/* https://leetcode.com/problems/merge-sorted-array/ */

/* Approach 1: merge then sort
Intuition: 合併之後再排序

Time complexity: O( (m+n)log(m+n) )
Space complexity: O(1)
*/

/* Approach 2: Two pointer
Intuition: 將 nums1 放到 nums1_copy
           p1 一開始指向 nums1_copy[0]，p2 一開始指向 nums2[0]。
           比較 nums1_copy[p1], nums2[p2] 大小之後，
           將小的放到 nums1[i], i=0:m+n-1
           
Time complexity: O(n)
Space complexity: O(n)
*/


/* Approach 3: Two pointer
Intuition: p1 一開始指向 nums1[m-1]，p2 一開始指向 nums2[n-1]。
           比較 nums1_copy[p1], nums2[p2] 大小之後，
           將大的放到 nums1[i], i=m+n-1:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        
        int i = m + n - 1;
        while(p1 >= 0 && p2 >= 0)
        {
            if(nums2[p2] > nums1[p1])
            {
                nums1[i--] = nums2[p2--];
            }
            else
            {
                nums1[i--] = nums1[p1--];
            }
        }
        
        // assign remainnig of nums2 to nums1
        while(p2 >= 0)
        {
            nums1[i--] = nums2[p2--];
        }
    }
};
