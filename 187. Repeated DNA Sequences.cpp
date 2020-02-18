/* https://leetcode.com/problems/repeated-dna-sequences/ */

/* Approach 1: HashSet + Sliding Window
Intuition:

Time complexity: O( (N-L)L )
Space complexity: O( (N-L)L )
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int L = 10;
        vector<string> ans;
        
        if(s.size() < L) return ans;
        
        unordered_map<int, int> umap;
        
        int toInt[27] = {0};
        toInt['A' - 'A'] = 0;
        toInt['C' - 'A'] = 1;
        toInt['G' - 'A'] = 2;
        toInt['T' - 'A'] = 3;
        
        for(int i = 0; i < s.size() - L + 1; ++i)
        {
            int key = 0;
            for(int start = i; start < i + L; ++start)
            {
                key <<= 2;
                key |= toInt[s[start] - 'A'];
            }
            
            ++umap[key];
            
            if(umap[key] == 2)
            {
                ans.push_back(s.substr(i, 10));
            }
        }
        
        return ans;
    }
};
