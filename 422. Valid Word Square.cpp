/* https://leetcode.com/problems/valid-word-square/ */

/* Approach 1:
Intuition:

Time complexity:O(m*n)
Space complexity: O(1)
*/

class Solution {
public:
    bool validWordSquare(vector<string>& words)
    {
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].size(); ++j)
            {
                if(j >= words.size() || i >= words[j].size()) return false;
                if(words[i][j] != words[j][i]) return false;
            }
        }
        
        return true;
    }
};
