/* https://leetcode.com/problems/median-of-two-sorted-arrays/ */

/* Approach 1:
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

/* Approach 3: quick selection
Intuition: 

Time complexity:O(n + m)
Space complexity: O(abs(m-n))
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        
        int k = nums1.size() / 2 + 1;
        double ans = quickSelect(nums1, 0, nums1.size() - 1, k);
        
        if(nums1.size() % 2 == 0)
        {
            ans += quickSelect(nums1, 0, nums1.size() - 1, k - 1);
            ans /= 2;
        }
            
        return ans;        
    }
    
    int quickSelect(vector<int> &arr, int start, int end, int k)
    {
        if(start == end) return arr[start];
        
        int left = start;
        int right = end;
        int pivot = arr[start + ((end - start) >> 1)];
        
        while(left <= right)
        {
            while(left <= right && arr[left] > pivot) ++left;
            while(left <= right && arr[right] < pivot) --right;
            
            if(left <= right)
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                ++left;
                --right;
            }
        }
        
        // [start, ..., right, , left, ..., end]
        if(start + k - 1 <= right)
        {
            return quickSelect(arr, start, right, k);
        }
        
        if(start + k - 1 >= left)
        {
            return quickSelect(arr, left, end, k - (left - start));
        }
        
        return arr[right + 1];
    }
};

/* Approach 4: Binary Search
Intuition:
Time complexity: O( (log(n) + log(m)) ∗ log(max−min))
Space complexity: O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len = nums1.size() + nums2.size();
        
        if(len % 2 == 0)
        {
            return (findKth(nums1, nums2, len / 2) + findKth(nums1, nums2, len / 2 + 1)) / 2;
        }
        
        return findKth(nums1, nums2, len / 2 + 1);
    }
    
    double findKth(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if(nums1.size() == 0) return nums2[k - 1];
        if(nums2.size() == 0) return nums1[k - 1];
        
        int n = nums1.size();
        int m = nums2.size();
        int start = min(nums1[0], nums2[0]);
        int end = max(nums1[n - 1], nums2[m - 1]);
        int count = 0;
        
        while(start + 1 < end)
        {
            int mid = start + ((end - start) >> 1);
            
            count = getLessOrEqualCount(nums1, mid) + getLessOrEqualCount(nums2, mid);
            
            if(count >= k)
            {
                end = mid;
            }
            else if(count < k)
            {
                start = mid;
            }
        }
        
        if(getLessOrEqualCount(nums1, start) + getLessOrEqualCount(nums2, start) >= k)
        {
            return start;
        }
        
        return end;
    }
    
    int getLessOrEqualCount(vector<int> &arr, int target)
    {
        int start = 0;
        int end = arr.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + ((end - start) >> 1);
            
            if(arr[mid] == target)
            {
                return mid + 1;
            }
            else if(arr[mid] <= target)
            {
                start = mid;
            }
            else if(arr[mid] > target)
            {
                end = mid;
            }
        }
        
        if(arr[start] > target) return start;
        if(arr[end] > target) return end;
        return arr.size();
    }
};

/* Approach 5: Binary Search
Intuition:
Time complexity: O(log(n + m))
Space complexity: O(1)
*/

