/* https://leetcode.com/problems/longest-palindrome/ */

/* Approach 1: Hash
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int longestPalindrome(string s)
    {
        if(s.size() == 0) return 0;
        
        int count = 0;
        bool singleLetter = false;
        unordered_map<char, int> umap;
        
        for(auto c : s)
        {
            ++umap[c];
        }
        
        for(auto it : umap)
        {
            if(it.second % 2 == 0)
            {
                count += it.second;
            }
            else
            {
                count += it.second - 1;
                singleLetter = true;
            }
        }
        
        if(singleLetter) ++count;
        
        return count;
    }
};
