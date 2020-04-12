/* https://leetcode.com/problems/string-matching-in-an-array/ */

/* Approach 1: Bruteforce
Intuition:

Time complexity:O(n^3)
Space complexity: O(1)
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words)
    {
        vector<string> ans;
        
        for(int i = 0; i < words.size(); ++i)
        {
            string w1 = words[i];
            
            for(int j = 0; j < words.size(); ++j)
            {
                if(j == i) continue;
                
                string w2 = words[j];
                
                if(w1.size() > w2.size()) continue;
                
                if(w2.find(w1) != string::npos)
                {
                    ans.push_back(w1);
                    break;
                }
            }
        }
        
        return ans;
    }
};
