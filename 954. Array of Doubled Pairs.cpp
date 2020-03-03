/* https://leetcode.com/problems/array-of-doubled-pairs/ */

/* Approach 1: Sort + Two Pointers
Intuition: 令 Dummy = 100001 因為 A[i] 最大到 100000。
           Coner Case: 排序的時候要注意負數，若是負數，則希望純數字小的排在前面。

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& A)
    {
        if(A.size() == 0) return true;
        
        sort(A.begin(), A.end(), [](int &a, int &b)
             {
                 if(a < 0 && b < 0)
                 {
                     return abs(a) < abs(b);
                 }
                 
                 return a < b;
             }
        );
        
        for(int slow = 0, fast = 1; slow < A.size() && fast < A.size(); ++slow)
        {
            if(A[slow] == 100001) continue;
            
            while(fast < A.size() && A[fast] != A[slow] * 2) ++fast;
            
            if(fast == A.size()) return false;
            
            A[fast] = 100001;
        }
        
        return true;
    }
};

/* Approach 2: HashMap + Sort
Intuition: 

Time complexity: O(n + klogk), k is the number of distinctive values. k <= n.
Space complexity: O(k)
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& A)
    {
        if(A.size() == 0) return true;
        
        unordered_map<int, int> umap;
        
        for(auto & a : A)
        {
            ++umap[a];
        }
        
        vector<int> keys;
        for(auto &it : umap)
        {
            keys.push_back(it.first);
        }
        
        sort(keys.begin(), keys.end(), [](int &a, int &b)
             {
                 return abs(a) < abs(b);
             }
        );
        
        for(auto &key : keys)
        {
            if(umap[2 * key] < umap[key]) return false;
            
            umap[2 * key] -= umap[key];
        }
        
        return true;
    }
};
