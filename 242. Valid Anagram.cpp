/* https://leetcode.com/problems/valid-anagram/ */

/* Approach 1: Hash
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> hashMap;
        
        for(auto c : s)
        {
            if(hashMap.find(c) == hashMap.end())
            {
                hashMap[c] = 1;
            }
            else
            {
                ++hashMap[c];
            }
        }
        
        for(auto c : t)
        {
            if(hashMap.find(c) == hashMap.end())
            {
                return false;
            }
            else
            {
                if(hashMap[c] <= 0)
                {
                    return false;
                }
                
                --hashMap[c];
            }
        }
            
        return true;
    }
};
