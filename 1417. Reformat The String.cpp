/* https://leetcode.com/problems/reformat-the-string/ */

/* Approach 1:
Intuition:

Time complexity:O(n)
Space complexity: O(n)
*/

class Solution {
public:
    string reformat(string s)
    {
        string ans;
        string letter;
        string digit;
        
        for(auto &c : s)
        {
            if(c >= '0' and c <= '9') digit.push_back(c);
            else if(c >= 'a' and c <= 'z') letter.push_back(c);
        }
        
        if(abs((int)digit.size() - (int)letter.size()) > 1) return "";
        
        int i = 0, j = 0;
        while(i < digit.size() && j < letter.size())
        {
            if(digit.size() > letter.size())
            {
                ans.push_back(digit[i]);
                ans.push_back(letter[j]);
            }
            else
            {
                ans.push_back(letter[j]);
                ans.push_back(digit[i]);
            }
            ++i;
            ++j;
        }
        if(i < digit.size()) ans.push_back(digit[i]);
        if(j < letter.size()) ans.push_back(letter[j]);
        
        return ans; 
    }
};
