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

/* Approach 2: Hash
Intuition: 

Time complexity: O(n)
Space complexity: O(n)
*/

