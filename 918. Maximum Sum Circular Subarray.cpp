/* https://leetcode.com/problems/maximum-sum-circular-subarray/ */

/* Approach 1: Prefix-sum
Intuition: 與 53. Maximum Subarray 類似，但輸入 array 的頭尾是相連的。

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A)
    {
        int maxPrefix = 0;
        int minPrefix = 0;
        int curPrefix = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int sumA = 0;
        
        for(auto & a : A)
        {
            sumA += a;
            curPrefix += a;
            maxSum = max(maxSum, curPrefix - minPrefix);
            minSum = min(minSum, curPrefix - maxPrefix);
            minPrefix = min(minPrefix, curPrefix);
            maxPrefix = max(maxPrefix, curPrefix);
        }
        
        return maxSum > 0 ? max(maxSum, sumA - minSum) : maxSum;
    }
};

/* Ref.: https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
