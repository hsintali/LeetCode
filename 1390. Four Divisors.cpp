/* https://leetcode.com/problems/four-divisors/ */

/* Approach 1: 
Intuition:

Time complexity: O(N * sqrt(n)), where N is size of nums, n is value of num
Space complexity: O(1)
*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int sum = 0;
        
        for(auto &num : nums)
        {
            int sq = sqrt(num);
            if(sq * sq == num) continue;
            
            int divisor;
            int count = 0;
            
            for(int i = 2; i <= sq; ++i)
            {
                if(num % i != 0) continue;
                
                ++count;
                if(count > 2) break;
                
                divisor = i;
            }
            
            if(count == 1)
            {
                sum += 1 + divisor + num / divisor + num;
            }
        }
        
        return sum;
    }
};
