/* https://leetcode.com/problems/guess-number-higher-or-lower/ */

/* Approach 1: Binary Search
Intuition:

Time complexity:O(logn)
Space complexity: O(1)
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n)
    {
        int start = 1;
        int end = n;
        
        while(start + 1 < end)
        {
            int mid = start + ((end - start) >> 1);
            
            int res = guess(mid);
            
            if(res == 0) return mid;
            
            if(res == 1)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return guess(start) == 0 ? start : end;
    }
};
