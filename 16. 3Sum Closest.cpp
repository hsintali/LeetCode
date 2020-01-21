/* https://leetcode.com/problems/3sum-closest/ */

/* Approach 1: Two pointer + 1 pointer
Intuition: 與 15. 3Sum 類似。
           
Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int diff = INT_MAX;
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < nums.size() - 2)
        {
            int start = i + 1;
            int end = nums.size() - 1;
            
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                
                if(abs(target - sum) < diff)
                {
                    diff = abs(target - sum);
                    ans = sum;
                }
                
                if(sum == target)
                {
                    return sum;
                }
                else if(sum < target)
                {
                    ++start;
                }
                else if(sum > target)
                {
                    --end;
                }
            }
            
            ++i;
        }
        
        return ans;
    }
};
