/*
https://leetcode.com/problems/longest-palindromic-substring/

Find its centers, than expand the string untill s[left] != s[right].

Time complexity : O(n^2). There are 2n−1 centers. 
Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
Space complexity : O(1). 
*/

class Solution {
public:
    string longestPalindrome(string s)
    {
        for(int middle = 0; middle < s.size(); ++middle)
        {
            findLongestFrom(s, middle , middle);
            findLongestFrom(s, middle , middle + 1);
        }
        
        return s.substr(start, longest);
    }
           
    void findLongestFrom(string &s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        
        if(longest < right - left + 1 - 2)
        {
            longest = right - left + 1 - 2;
            start = left + 1;
        }
    }
    
    int longest = 0;
    int start = 0;
};
