/* https://leetcode.com/problems/word-abbreviation/ */

/* Approach 1: Hash + 模擬法
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict)
    {
        vector<string> ans;
        
        if(dict.size() == 0) return ans;
        
        unordered_map<string, int> umap;
        
        int round = 1;
        for(auto s : dict)
        {
            string abbr = getAbbr(s, round);
            ans.push_back(abbr);
            ++umap[abbr];
        }
        
        // rule 2
        bool isNotUnique = true;
        while(isNotUnique)
        {
            isNotUnique = false;
            ++round;
            
            for(int i = 0; i < dict.size(); ++i)
            {
                if(umap[ans[i]] > 1)
                {
                    isNotUnique = true;
                    ans[i] = getAbbr(dict[i], round);
                    ++umap[ans[i]];
                }
            }           
        }
        
        return ans;
    }
    
    string getAbbr(string s, int round)
    {
        // rule 3
        if(s.size() <= round + 2)
        {
            return s;
        }
        
        // rule 1
        string abbr = s.substr(0, round) + to_string(s.size() - round - 1) + s[s.size() - 1];

        return abbr;
    }
};
