/* https://leetcode.com/problems/product-of-array-except-self/ */

/* Approach 1: left product and right product
Intuition:

Time complexity:O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> leftProduct(nums.size(), 1), rightProduct(nums.size(), 1);
        
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            leftProduct[i + 1] = leftProduct[i] * nums[i]; 
        }
        
        for(int i = nums.size() - 1; i > 0; --i)
        {
            rightProduct[i - 1] = rightProduct[i] * nums[i]; 
        }
        
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            ans.push_back(leftProduct[i] * rightProduct[i]);
        }
        
        return ans;
    }
};

/* Approach 2: left product and right product
Intuition:

Time complexity:O(n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {   
        vector<int> ans(nums.size(), 1);
        
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            ans[i + 1] = ans[i] * nums[i]; 
        }
        
        int rightProduct = 1;
        
        for(int i = nums.size() - 1; i > 0; --i)
        {
            rightProduct *= nums[i];
            ans[i - 1] *= rightProduct; 
        }
        
        return ans;
    }
};
