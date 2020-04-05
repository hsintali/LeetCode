/* https://leetcode.com/problems/count-largest-group/ */

/* Approach 1: hash
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> hash;
        int maxSize = 0;
        
        for(int i = 1; i <= n; ++i)
        {
            maxSize = max(maxSize, ++hash[getSum(i)]);
        }        
        
        int count = 0;
        for(auto &g : hash)
        {
            if(g.second == maxSize) ++count;
        }
        
        return count;
    }
    
    int getSum(int n)
    {
        int sum = 0;
        
        while(n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        
        return sum;
    }
};
