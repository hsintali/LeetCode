/* https://leetcode.com/problems/construct-k-palindrome-strings/ */

/* Approach 1: hash
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool canConstruct(string s, int k)
    {
        if(k > s.size()) return false;
        
        vector<int> count(26, 0);
        
        for(char &c : s)
        {
            ++count[c - 'a'];
        }
        
        int oddCount = 0;
        for(auto &p : count)
        {
            if(p % 2 == 1) ++oddCount;
        }
        
        if(oddCount > k) return false;
        
        return true;
    }
};
