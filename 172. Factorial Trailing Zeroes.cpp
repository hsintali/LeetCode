/* https://leetcode.com/problems/factorial-trailing-zeroes/ */

/* Approach 1: 數學題
Intuition: 尾巴的 0 由 10 構成，10 由 2 和 5 構成。
           每個偶數都會有 2 ，數量比 5 多，因此要考慮 5 的數量。
           因此當 n = 100，100/5=20，100! 至少會有 20 個 0。
           但又因為 25 = 5 * 5，會多一個 5，所以要計算 100/25 = 4，會多出 4 個 5，即 4 個 0。
           以此類推，zero-trailing = n/5 + n/5^2 + ... 直到 n/5^i = 0。

Time complexity: O(logn)
Space complexity: O(1)
*/

class Solution {
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        
        for(long long i = 5; n / i > 0; i *= 5)
        {
            ans += n/i;
        }
        
        return ans;
    }
};
