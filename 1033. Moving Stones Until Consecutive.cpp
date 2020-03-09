/* https://leetcode.com/problems/moving-stones-until-consecutive/ */

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> nums = {a, b ,c};
        
        sort(nums.begin(), nums.end());
        
        if(nums[2] - nums[0] == 2) return vector<int>({0, 0});
        
        int max = (nums[2] - nums[1] - 1) + (nums[1] - nums[0] - 1);
        
        int min = 1;
        if(nums[2] - nums[1] - 1 > 1 && nums[1] - nums[0] - 1 > 1) min += 1;
        
        return vector<int>({min, max});
    }
};
