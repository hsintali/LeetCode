/*
https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:
    string longestPalindrome(string s)
    {
        longest = 0;
        start = 0;
        
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
