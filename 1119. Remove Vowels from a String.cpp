/* https://leetcode.com/problems/remove-vowels-from-a-string/ */

/* Approach 1:
Intuition: 送分題，但要注意刪除時要 S.erase(it--) 有 it--

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    string removeVowels(string S)
    {
        for(auto it = S.begin(); it != S.end(); ++it)
        {
            char c = *it;
            if(c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u')
            {
                S.erase(it--);
            }
        }
        
        return S;
    }
};
