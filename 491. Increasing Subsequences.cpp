/* https://leetcode.com/problems/increasing-subsequences/ */

/* Approach 1: DFS
Intuition:

Time complexity:  O(2^n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> seq;
        dfs(ans, seq, nums, 0);
        return ans;
    }
    
    void dfs(vector<vector<int>> &ans, vector<int> &seq, vector<int> &nums, int start)
    {
        if(seq.size() > 1) ans.push_back(seq);
        
        if(start == nums.size()) return;
        
        unordered_set<int> uset;
        for(int i = start; i < nums.size(); ++i)
        {
            if((seq.empty() || nums[i] >= seq.back()) && uset.count(nums[i]) == 0)
            {
                seq.push_back(nums[i]);
                dfs(ans, seq, nums, i + 1);
                seq.pop_back();
                uset.insert(nums[i]);
            }
        }
    }
};
