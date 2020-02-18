/* https://leetcode.com/problems/first-unique-character-in-a-string/ */

/* Approach 1: hashMap
Intuition:

Time complexity: O(n)
Space complexity: O(1), 26 lowercast letter
*/

class Solution {
public:
    int firstUniqChar(string s)
    {
        if(s.size() == 0) return -1;
        
        int arr[26] = {0};
        
        for(auto c : s)
        {
            ++arr[c - 'a'];
        }
        
        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i] - 'a';
            
            if(arr[c] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
