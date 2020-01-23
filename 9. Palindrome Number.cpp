/* https://leetcode.com/problems/palindrome-number/ */

/* Approach 1: two pointer
Intuition: convert to string then two pointer traversal

Time complexity: O(n)
Space complexity: O(n), the string
*/

class Solution {
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        
        for(int left = 0, right = s.size() - 1; left < right; ++left, --right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
        }
        
        return true;
    }
};

/* Approach 2: math
Intuition:

Time complexity: O(logn)
Space complexity: O(1)
*/

