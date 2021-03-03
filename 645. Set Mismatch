/* https://leetcode.com/problems/set-mismatch/ */

/* Approach 1: brute force
Intuition:

Time complexity:O(n^2)
Space complexity: O(1)
*/



/* Approach 2: sorting
Intuition:

Time complexity:O(nlogn)
Space complexity: O(logn)
*/



/* Approach 3: hashMap
Intuition:

Time complexity:O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int count[10001]{0};
        int dup = 0;
        int missing = 0;
        
        for(auto n : nums)
        {
            ++count[n];
        }
        
        for(int i = 1; i <= nums.size(); ++i)
        {
            if(count[i] == 2)
            {
                dup = i;
            }
            else if(count[i] == 0)
            {
                missing = i;
            }
        }
        
        return vector<int>({dup, missing});
    }
};

/* Approach 4: multiple negative
Intuition: Advanced hashmap using input nums array to mark the count of a number.

Time complexity:O(n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int dup, miss;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)
            {
                nums[index] *= -1;
            }
            else
            {
                dup = index + 1;
            }
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0)
            {
                miss = i + 1;
            }
        }
        
        return vector<int>({dup, miss});
    }
};

/* Approach 5: XOR
Intuition:

Time complexity:O(n)
Space complexity: O(1)
*/



/* Approach 6: math
Intuition: Let x be the duplicated and y be the missing number.
           By using the facts that:
              1. 1 + 2 + ... + n = n*(n+1)/2; // But even if you do not know this formula you can get it in O(n) time and O(1) space.
              2. 1^2 + 2^2 + ... + n^2 = n*(n+1)*(2*n+1)/6; // Again if you do not know this formula, you can get it in O(n) time and O(1) space.
           Now, let us consider number A = n*(n+1)/2 - Sum(nums) ==> y - x
                                       B = n*(n+1)*(2*n+1)/6 - -sum(i*i for i in nums) ==> y^2 - x^2
           So, we can solve x, y

Time complexity:O(n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        long long int n = nums.size();
        long long int normalSum = n * (n + 1) / 2;
        long long int squareNormalSum = n * (n + 1) * (2 * n + 1) / 6;
        
        long long int sum = 0;
        long long int squareSum = 0;
        for(auto n : nums)
        {
            sum += n;
            squareSum += n * n;
        }
        
        long long int A = normalSum - sum;
        long long int B = squareNormalSum - squareSum;
        int dup = (B/A - A) / 2;
        int miss = (B/A + A) / 2;
        
        return vector<int>({dup, miss});
    }
};

/* Approach 7: swap to corresponding bucket
Intuition: Putting each nums[i] into the position with index nums[i] - 1
           Then, the array becomes [1,2,3,4,5...,n]
           So we can find the duplicate number when nums[i] != i + 1

Time complexity:O(n)
Space complexity: O(1)
*/

