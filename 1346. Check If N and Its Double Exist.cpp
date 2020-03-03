/* https://leetcode.com/problems/check-if-n-and-its-double-exist/ */

/* Approach 1: Sort + Binary Search
Intuition: Coner Case: arr[i] == 0 的時候，要判斷是否重複找到 i。

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        if(arr.size() == 0) return false;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); ++i)
        {
            int index = binarySearch(arr, arr[i] * 2);
            
            if(index != -1 && index != i)
            {
                return true;
            }
        }
        
        return false;
    }
    
    int binarySearch(vector<int>& arr, int target)
    {
        int start = 0;
        int end = arr.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + ((end - start) >> 1);
            
            if(arr[mid] == target)
            {
                return mid;
            }
            else if(arr[mid] < target)
            {
                start = mid;
            }
            else if(arr[mid] > target)
            {
                end = mid;
            }
        }
        
        if(arr[start] == target) return start;
        if(arr[end] == target) return end;
        return -1;
    }
};

/* Approach 2: Hash
Intuition: Coner Case: 1. a == 0 的時候，要避免是否找到重複的 a。
                       2. a 是奇數的時候不能除2，因為都是 int。

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        if(arr.size() == 0) return false;
        
        unordered_set<int> uset;
        
        for(auto &a : arr)
        {
            if(uset.count(a) == 1)
            {
                return true;
            }
            
            uset.insert(a * 2);
            
            if(a % 2 == 0) uset.insert(a / 2);
        }
        
        return false;
    }
};
