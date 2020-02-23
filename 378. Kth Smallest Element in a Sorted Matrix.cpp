/* https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/ */

/* Approach 1: Sort
Intuition:

Time complexity: O( n^2 * log(n^2) )
Space complexity: O(n^2)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        
        if(n == 0 || matrix[0].size() == 0) return 0;
        
        vector<int> arr;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                arr.push_back(matrix[i][j]);
            }
        }
                         
        sort(arr.begin(), arr.end());
        
        return arr[k - 1];
    }
};

/* Approach 2: Quick Select
Intuition:

Time complexity: O(n^2)
Space complexity: O(n^2)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        
        if(n == 0 || matrix[0].size() == 0) return 0;
        
        vector<int> arr;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                arr.push_back(matrix[i][j]);
            }
        }
                         
        return quickSelect(arr, 0, arr.size() - 1, k);
    }
    
    int quickSelect(vector<int> &A, int start, int end, int k)
    {
        if(start == end) return A[start];
        
        int left = start;
        int right = end;
        int pivot = A[left + ((right - left) >> 1)];
        
        while(left <= right)
        {
            while(left <= right && A[left] < pivot)
            {
                ++left;
            }
            
            while(left <= right && A[right] > pivot)
            {
                --right;
            }
            
            if(left <= right)
            {
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
                ++left;
                --right;
            }
        }
        
        if(start + k - 1 <= right)
        {
            return quickSelect(A, start, right, k);
        }
        
        if(start + k - 1 >= left)
        {
            return quickSelect(A, left, end, k - (left - start));
        }
        
        return A[right + 1];
    }
};

/* Approach 3: minHeap
Intuition: 將每個 row 的第一個元素放到 minHeap，
           然後每次 pop 最小的，同時放入 pop 出來的那個值所屬的 row 的下一個值。
           pop 到第 k 次後，就是答案。

Time complexity: O(klogn)
Space complexity: O(n)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int ans = 0;
        int n = matrix.size();
        
        if(n == 0 || matrix[0].size() == 0) return ans;
        
        // pair.first: val, pair.second:indices
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> minHeap;
        
        for(int i = 0; i < n; ++i)
        {
            int leftVal = matrix[i][0];
            pair<int, int> indices = {i, 0};
            minHeap.push(make_pair(leftVal, indices));
        }
        
        for(int count = 1; count <= k; ++count)
        {
            int val = minHeap.top().first;
            int i = minHeap.top().second.first;
            int j = minHeap.top().second.second;
            
            minHeap.pop();
            
            if(count == k)
            {
                ans = val;
            }
            else if(j < n - 1)
            {
                int largerVal = matrix[i][j + 1];
                pair<int, int> indices = {i, j + 1};
                minHeap.push(make_pair(largerVal, indices));
            }
        }
        
        return ans;
    }
    
    struct compare
    {
        bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
        {
            return a.first > b.first;
        }
    };
};
