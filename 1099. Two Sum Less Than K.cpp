/* https://leetcode.com/problems/two-sum-less-than-k/ */

/* Approach 1: Brute force
Intuition:
           
Time complexity: O(n^2)
Space complexity: O(1)
*/

/* Approach 1: Sort + Two pointer
Intuition:
           
Time complexity: O(nlogn)
Space complexity: O(n), without modifying the input array
*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K)
    {
        vector<int> sortedArr;
        sortedArr.assign(A.begin(), A.end());
        sort(sortedArr.begin(), sortedArr.end());
        
        int left = 0;
        int right = A.size() - 1;
        int ans = -1;
        
        while(left < right)
        {
            int sum = sortedArr[left] + sortedArr[right];
            
            if(sum < K)
            {
                ++left;
                ans = max(ans, sum);
            }
            else if(sum >= K)
            {
                --right;
            }
        }
        
        return ans;
    }
};
