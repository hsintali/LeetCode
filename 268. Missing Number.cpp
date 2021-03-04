/* https://leetcode.com/problems/missing-number/ */

/* Approach 1: Use input array to indicate if the number exists
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            int index = nums[i];
            while(index >= 0 && index < nums.size())
            {
                int val = nums[index];
                nums[index] = -1;
                index = val;
            }
        }
        
        int ans = nums.size();
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] >= 0)
            {
                ans = i;
            }
        }
        
        return ans;
    }
};

/* Approach 2: Sorting
Intuition:

Time complexity:  O(nlogn)
Space complexity: O(logn)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        if(nums[nums.size() - 1] != nums.size())
        {
            return nums.size();
        }
        
        if(nums[0] != 0)
        {
            return 0;
        }
        
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        
        return -1;
    }
};

/* Approach 3: HashSet
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        unordered_set<int> uset(nums.begin(), nums.end());
        
        for(int i = 0; i <= nums.size(); ++i)
        {
            if(uset.count(i) == 0)
            {
                return i;
            }
        }
        
        return -1;
    }
};

/* Approach 4: Bit manipulation
Intuition: We have index all from 0 to n - 1 and values from 0 to n with a missing value.
           Then we can XRO for both index: 0, 1, 2, 3, ..., n - 1, n (with additional n)
                                and value: 0, 1, 3, 4, ..., n - 1, n (with missing 2)
           After the XOR for all above numbers, we can find that missing value is 2.

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = nums.size();
        for(int i = 0; i < nums.size(); ++i)
        {
            ans ^= nums[i] ^ i;
        }
        
        return ans;
    }
};

/* Approach 5: Gauss's Formula
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

