/* https://leetcode.com/problems/consecutive-numbers-sum/ */

/* Approach 1: 數學題
Intuition: 

The thought process goes like this- Given a number N, we can possibly write it as a sum of 2 numbers, 3 numbers, 4 numbers and so on.
Let's assume the fist number in this series be x. Hence, we should have
k terms: x + (x+1) + (x+2)+...+ (x+k-1) = N
kx + k*(k-1)/2 = N implies
kx = N - k*(k-1)/2
So, we can calculate the RHS for every value of k and if it is a multiple of k then we can construct a sum of N using k terms starting from x.
Now, the question arises, till what value of k should we loop for? That's easy. In the worst case, RHS should be greater than 0. That is
N - k*(k-1)/2 > 0 which implies
k*(k-1) < 2N which can be approximated to
k*k < 2N ==> k < sqrt(2N)
Hence the overall complexity of the algorithm is O(sqrt(N))
           
Time complexity: O(sqrt(N))
Space complexity: O(1)
*/

class Solution {
public:
    int consecutiveNumbersSum(int N)
    {
        int ans = 1;
        
        for(int k = 2; k < sqrt(2 * N); ++k)
        {
            int val = N - (k * (k - 1) / 2);
            
            if (val % k == 0)
            {
                ++ans;
            }
        }
        
        return ans;
    }
};

/* Approach 1: Brute Force
Intuition: 
           
Time complexity: O(n^2)
Space complexity: O(1)
*/
