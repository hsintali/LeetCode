/* https://leetcode.com/problems/reverse-string/ */

class Solution {
public:
    void reverseString(vector<char>& s) {
        char buffer;       
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right)
        {
            buffer = s[left];
            s[left] = s[right];
            s[right] = buffer;
            
            ++left;
            --right;
        } 
    }
};
