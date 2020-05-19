/* https://leetcode.com/problems/permutation-in-string/ */

/* Approach 1: HashMap + Sliding Window
Intuitions
Time complexity:  O(n1 + (n2 - n1)), n1 is the length of s1, n2 is the length of s2
Space complexity: O(26) = O(1)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.size() > s2.size()) return false;
        
        int count[26];
        for(int i = 0; i < 26; ++i)
        {
            count[i] = 0;
        }
        
        for(auto &c : s1)
        {
            ++count[c - 'a'];
        }
        
        int n = s1.size();
        
        for(int i = 0; i < n; ++i)
        {
            --count[s2[i] - 'a'];
        }
        
        int det = 0;
        for(int i = 0; i < 26; ++i)
        {
            det += abs(count[i]);
        }
        
        if(det == 0) return true;
        
        for(int left = 0, right = n; right < s2.size(); ++left, ++right)
        {
            det -= abs(count[s2[left] - 'a']);
            det -= abs(count[s2[right] - 'a']);
            
            ++count[s2[left] - 'a'];
            --count[s2[right] - 'a'];
            
            det += abs(count[s2[left] - 'a']);
            det += abs(count[s2[right] - 'a']);
            
            if(det == 0) return true;
        }
        
        return false;
    }
};
