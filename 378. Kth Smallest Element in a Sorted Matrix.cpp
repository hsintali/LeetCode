/* https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/ */

/* Approach 0: Brute Force
Intuition:

Time complexity: O(k * n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        
        int count = 0;
        int ans = INT_MIN;
        
        while(count < k) // O(k)
        {
            ans = getLeastGreater(matrix, ans); // O(n^2)
            count += calcCount(matrix, ans);    // O(n^2)
            
            if(count >= k)
            {
                break;
            }
        }
        
        return ans;
    }
    
    int calcCount(vector<vector<int>> &matrix, int target)
    {
        int count = 0;
        int n = matrix.size();
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == target)
                {
                    ++count;
                }
            }
        }
        
        return count;
    }
    
    int getLeastGreater(vector<vector<int>> &matrix, int target)
    {
        int ans = INT_MAX;
        int n = matrix.size();
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] <= target) continue;
                
                ans = min(ans, matrix[i][j]);

            }
        }
        
        return ans;
    }
};

/* Approach 1: Sort
Intuition:

Time complexity: O( n^2 * log(n^2) ), 可優化為 O( n^2 * log(n) ) 透過 merge k sorted list 的方法。
Space complexity: O(n^2), 可優化為 O(1)
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

/* Approach 2-1: Quick Select
Intuition:

Time complexity: O(n^2)
Space complexity: O(n^2), 可優化為 O(1)
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

/* Approach 2-2: Quick Select
Intuition:

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        
        if(n == 0 || matrix[0].size() == 0) return 0;
                             
        return quickSelect(matrix, n, 0, n * n - 1, k);
    }
    
    int quickSelect(vector<vector<int>> &A, int n, int start, int end, int k)
    {
        if(start == end) return A[start / n][start % n];
        
        int left = start;
        int right = end;
        int index = left + ((right - left) >> 1);
        int pivot = A[index / n][index % n];
        
        while(left <= right)
        {
            while(left <= right && A[left / n][left % n] < pivot)
            {
                ++left;
            }
            
            while(left <= right && A[right / n][right % n] > pivot)
            {
                --right;
            }
            
            if(left <= right)
            {
                int temp = A[left / n][left % n];
                A[left / n][left % n] = A[right / n][right % n];
                A[right / n][right % n] = temp;
                ++left;
                --right;
            }
        }
        
        if(start + k - 1 <= right)
        {
            return quickSelect(A, n, start, right, k);
        }
        
        if(start + k - 1 >= left)
        {
            return quickSelect(A, n, left, end, k - (left - start));
        }
        
        return A[(right + 1) / n][(right + 1) % n];
    }
};

/* Approach 3: minHeap
Intuition: 此問題可簡化為: Kth Smallest Number in N Sorted Lists (with size N)
           將每個 row 的第一個元素放到 minHeap，
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

/* Approach 4: Binary Search
Intuition:

Time complexity: O(N ∗ log(max−min))
Space complexity: O(1)
*/

/* Approach 5: from paper
Intuition:

Time complexity: O(N), O(# of row)
Space complexity:
*/
