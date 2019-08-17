/* https://leetcode.com/problems/valid-palindrome/ */

class Solution {
public:
    bool isPalindrome(string s)
    {
        if(s.size() == 0) return true;
        
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right)
        {
            while(!isalnum(s[left]) && left < right) ++left;
            while(!isalnum(s[right]) && left < right) --right;

            if(toupper(s[left]) != toupper(s[right])) return false;
            
            ++left;
            --right;
        }
        
        return true;
    }
};
