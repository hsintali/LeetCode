/* https://leetcode.com/problems/maximum-product-subarray/ */

/* Approach 1: DP
Intuition: Since there exists postive and negative number in the array, 
           we should keep the maximun and minmin (may be negative) number then multiplied by current number.

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int maxProduct = 1;
        int minProduct = 1;
        int res = INT_MIN;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int ma = max(nums[i], max(maxProduct * nums[i], minProduct * nums[i]));
            int mi = min(nums[i], min(maxProduct * nums[i], minProduct * nums[i]));
            maxProduct = ma;
            minProduct = mi;
            res = max(res, maxProduct);
        }
        
        return res;
    }
};
