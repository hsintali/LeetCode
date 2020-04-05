/* https://leetcode.com/problems/longest-happy-string/ */

/* Approach 1: Greedy
Intuition:

Time complexity: O(n) = O(a+b+c)
Space complexity: O(1)
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        string s;
        vector<pair<int, char>> pairs;
        pairs.push_back(make_pair(a, 'a'));
        pairs.push_back(make_pair(b, 'b'));
        pairs.push_back(make_pair(c, 'c'));
        
        int count = 0;
        while(s.size() == count)
        {
            sort(pairs.begin(), pairs.end());
            
            if(count >= 2)
            {                
                for(int p = 2; p >= 0; --p)
                {
                    if(pairs[p].first <= 0) continue;
                    
                    if(s[count - 1] != pairs[p].second || s[count - 2] != pairs[p].second)
                    {
                        s.push_back(pairs[p].second);
                        --pairs[p].first;
                        break;
                    }
                }
            }
            else
            {
                s.push_back(pairs[2].second);
                --pairs[2].first;
            }
            
            ++count;
        }
        
        return s;
    }
};
