/* https://leetcode.com/problems/queries-on-a-permutation-with-key/ */

/* Approach 1: Bruteforce
Intuition:

Time complexity:O(qm)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m)
    {
        vector<int> ans;
        
        vector<int> p(m, 0);
        for(int i = 0; i < m; ++i)
        {
            p[i] = i + 1;
        }
        
        for(auto &q : queries)
        {
            for(int i = 0; i < m; ++i)
            {
                if(p[i] == q)
                {
                    p.erase(p.begin() + i);
                    p.insert(p.begin(), q);
                    ans.push_back(i);
		    break;
                }
            }
        }
        
        return ans;
    }
};
