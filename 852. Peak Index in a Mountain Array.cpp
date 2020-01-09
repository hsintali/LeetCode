/* https://leetcode.com/problems/peak-index-in-a-mountain-array/ */

/* Approach 1: binary search
Intuition:

Time complexity: O(log n)
Space complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int start = 0;
        int end = A.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
            {
                return mid;
            }
            else if(A[mid] > A[mid - 1])
            {
                start = mid;
            }
            else if(A[mid] < A[mid - 1])
            {
                end = mid;
            }
        }
        
        return A[start] > A[end] ? start : end;
    }
};
