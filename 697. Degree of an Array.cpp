/* https://leetcode.com/problems/degree-of-an-array/ */

/* Approach 1:

Intuition: 先找出各個元素的第一次位置，最後一次位置，及次數。
           找出最高頻的數之後再分別計算最短距離。

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        if(nums.size() <= 1) return nums.size();
        
        unordered_map<int, int> start, end, count;
        int degree = 0;
        
        // find the freq. for each elements
        // find the start, end index of each elements
        for(int i = 0; i < nums.size(); ++i)
        {
            int val = nums[i];
            if(count.find(val) == count.end())
            {
                start[val] = i;
            }

            end[val] = i;
            ++count[val];
            degree = max(degree, count[val]);
        }
        
        int ans = INT_MAX;
        
        // find the shortest length
        for(auto &e : count)
        {
            if(e.second == degree)
            {
                ans = min(ans, end[e.first] - start[e.first] + 1);
            }
        }
        
        return ans;
    }
};
