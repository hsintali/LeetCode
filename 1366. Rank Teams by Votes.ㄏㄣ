/* https://leetcode.com/problems/rank-teams-by-votes/ */

/* Approach 1: Hash + Sort
Intuition: 先計算各隊各次序的得分，再排序。

Time complexity: O(26N + 26^2 * log26), N is votes.size()
Space complexity: O(26 * 26)
*/

class Solution {
public:
    string rankTeams(vector<string>& votes)
    {
        if(votes.size() == 0 || votes[0].size() == 0) return "";
        
        if(votes.size() == 1 || votes[0].size() == 1) return votes[0];
        
        // scores[team][voter]
        vector<vector<int>> scores(26 , vector<int>(26 + 1, 0));
        
        for(char &c : votes[0])
        {
            scores[c - 'A'][26] = c;
        }
        
        for(auto &vote : votes)
        {
            for(int i = 0; i < vote.size(); ++i)
            {
                ++scores[vote[i] - 'A'][i];
            }
        }
        
        sort(scores.begin(), scores.end(), [](auto &a, auto &b)
             {
                 for(int i = 0; i < a.size() - 1; ++i)
                 {
                     if(a[i] != b[i]) return a[i] > b[i];
                 }
                 
                 return a.back() < b.back();
             }
        );
        
        string ans;
        
        for(int i = 0; i < votes[0].size(); ++i)
        {
            ans += scores[i][26];
        }
        
        return ans;
    }
};
