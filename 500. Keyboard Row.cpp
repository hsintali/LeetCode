/* https://leetcode.com/problems/keyboard-row/ */

/* Approach 1: HashSet
Intuition: 

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string> ans;
        
        unordered_set<char> row1, row2, row3;
        
        row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        for(auto word : words)
        {
            bool r1 = true, r2 = true, r3 = true;
            
            for(auto c : word)
            {
                if(c < 'a')
                {
                    c = c - 'A' + 'a';
                }
                
                r1 &= row1.find(c) != row1.end();
                r2 &= row2.find(c) != row2.end();
                r3 &= row3.find(c) != row3.end();
            }
            
            if(r1 || r2 || r3)
            {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
