/* https://leetcode.com/problems/valid-palindrome-ii/ */

/* Approach 1: Two pointer
Intuition: 從頭和尾開始各自逐一比較，遇到不同可跳過一次。
           
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool validPalindrome(string s)
    {
        if(s.size() == 0) return false;
        
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);;
            }
            
            ++left;
            --right;
        }
        
        return true;
    }
    
    bool isPalindrome(string &s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            
            ++left;
            --right;
        }
        
        return true;
    }
};
