/* https://leetcode.com/problems/longest-substring-without-repeating-characters/ */

/*
Intuition: brute force
Check all the substring one by one to see if it has no duplicate character by hashset.
Time complexity: O(n^2)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {       
        for(int start = 0; start < s.size(); ++start)
        {
            findLongest(s, start);
        }
        
        return length;
    }
    
    void findLongest(string s, int left)
    {
        int right = left + 1;
        
        unordered_set<char> substring;
        substring.insert(s[left]);

        while(right < s.size() && substring.find(s[right]) == substring.end())
        {
            substring.insert(s[right]);
            ++right;
        }
        
        if(length < right - left)
        {
            length = right - left;
        }
    }
    
    int length = 0;
};
