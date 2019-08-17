/* https://leetcode.com/problems/implement-strstr/ */

/*
Intuition: brute force

Time complexity: O(mn)

O(m+n): KMP pattern matching
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;
        
        int n = haystack.size();
        int m = needle.size();
        
        for(int i = 0; i < n - m + 1; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(haystack[i + j] != needle[j]) break;
                if(j == m - 1) return i;
            }
        }
        
        return -1;
    }
};
