/* https://leetcode.com/problems/longest-substring-without-repeating-characters/ */

/* Approach 1: Brute Force
Intuition:
Check all the substring one by one to see if it has no duplicate character by hashset.

Time complexity: O(n^2)
Space complexity: O(k), where kk is the size of the Set k <= n
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

/* Approach 2: Sliding Window

Time complexity: O(2n)
Space complexity: O(k), where kk is the size of the Set k <= n
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {   
        int left = 0, right = 0;
        int length = 0;
        unordered_set<char> substring;
        
        while(left < s.size() && right < s.size())
        {
            if(substring.find(s[right]) == substring.end())
            {
                substring.insert(s[right++]);
                length = max(length, right - left);
            }
            else
            {
                substring.erase(s[left++]);
            }          
        }
             
        return length;
    }
};
