/* https://leetcode.com/problems/find-k-closest-elements/ */

/* Approach 1: binary search + sliding window
Intuition:先透過 binary search 找出最接近 x 的 index，在找出最接近的區間。

Time complexity: O(log(n) + k)
Space complexity: O(1)
Coner case:需要注意當input只有一個的時候
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int start = 0;
        int end = arr.size() - 1;
        
        // binary search to find the index of the closest element
        while(start + 1 < end)
        {
            int mid = start + (end - start)/2;
            
            if (arr[mid] <= x)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        // init the range of size 1 closest to x
        if(abs(arr[start] - x) < abs(arr[end] - x))
        {
            end = start;
        }
        else
        {
            start = end;
        }
        
        // find the range of k nums closest to x
        while(end - start + 1 < k)
        {
            if(isStartColser(arr, start, end, x))
            {
                --start;
            }
            else
            {
                ++end;
            }
        }
        
        return vector<int>(arr.begin() + start, arr.begin() + end + 1);
    }
    
    bool isStartColser(vector<int>& arr, int start, int end, int x)
    {
        if(start == 0) return false;
        if(end == arr.size() - 1) return true;
        
        if(abs(arr[start - 1] - x) <= abs(arr[end + 1] - x))
        {
            return true;
        }
        
        return false;
    }
};
