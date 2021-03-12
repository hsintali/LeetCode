/* https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/ */

/* Approach 1: Set
Intuition:

Time complexity:O(NK)
Space complexity: O(NK)
*/

class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        if(k >= s.size()) return false;
        unordered_set<string> uset;
        for(int i = 0; i < s.size() - (k - 1); ++i)
        {
            uset.insert(s.substr(i, k));
        }
        
        return uset.size() == pow(2, k);
    }
};
