/* https://leetcode.com/problems/jewels-and-stones/ */

/* Approach 1: Brute forece
Intuition:
Time complexity: O(S.size * J.size)
Space complexity: O(1)
*/

class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        int count = 0;
        for(int i = 0; i < S.size(); ++i)
        {
            for(int j = 0; j < J.size(); ++j)
            {
                if(S[i] == J[j])
                {
                    ++count;
                    break;
                }
            }
        }
        
        return count;
    }
};

/* Approach 2: HashSet
Intuition:
Time complexity: O(S.size + J.size)
Space complexity: O(J.size)
*/

class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        int count = 0;
        unordered_set<char> jSet;
        
        for(auto j : J)
        {
            jSet.insert(j);
        }
        
        for(int i = 0; i < S.size(); ++i)
        {
            if(jSet.count(S[i]) == 1)
            {
                ++count;
            }
        }
        
        return count;
    }
};
