/* https://leetcode.com/problems/ransom-note/ */

/* Approach 1: hashMap
Intuition:

Time complexity:  O(m + n)
Space complexity: O(26)
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if(ransomNote.size() > magazine.size()) return false;
        
        int freq[26] = {0};
        
        for(auto &c : magazine)
        {
            ++freq[c - 'a'];
        }
        
        for(auto &c : ransomNote)
        {
            if(freq[c - 'a'] > 0)
            {
                --freq[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};
