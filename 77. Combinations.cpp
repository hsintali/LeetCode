/* https://leetcode.com/problems/combinations/ */

/* Approach 1: DFS
Intuition:

Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> subSet;
        
        dfs(n, k, 1, subSet, ans);
        
        return ans;
    }
    
    void dfs(int n, int k, int startIndex, vector<int> &subSet, vector<vector<int>> &ans)
    {
        if(subSet.size() == k)
        {
            ans.push_back(subSet);
            return;
        }
        
        for(int i = startIndex; i <= n; ++i)
        {
            subSet.push_back(i);
            dfs(n, k, i + 1, subSet, ans);
            subSet.pop_back();
        }
    }
};
