/* https://leetcode.com/problems/3sum/ */

/* Approach 1: Two pointer + 1 pointer
Intuition: 假設此數組為 (a, b, c) 且 a <= b <= c。使用 i 指針遍歷 nums 找出 a，再用 two sum 找出 b + c = a。
           注意
           coner case 1: a 固定時，可能有一組以上的 (b, c)
           coner case 2: nums 中可能遇到重複的 b, c ，需要跳過
           coner case 3: nums 中可能遇到重複的 a ，需要跳過
           
Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        
        if(nums.size() < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        // using i traverse nums to find 'a' such that a <= b <= c (a, b, c)
        int i = 0; 
        
        // two sum
        while(i < nums.size() - 2)
        {
            int target = -nums[i];
            
            int start = i + 1;
            int end = nums.size() - 1;
            
            while(start < end)
            {
                if(nums[start] + nums[end] == target)
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    
                    // coner case: more than one b,c such that b + c = a
                    ++start;
                    --end;
                    
                    // coner case: duplicate element, 'b', 'c'
                    while(start < end && nums[start] == nums[start - 1]) ++start;
                    while(start < end && nums[end] == nums[end + 1]) --end;
                }
                else if(nums[start] + nums[end] < target)
                {
                    ++start;
                }
                else if(nums[start] + nums[end] > target)
                {
                    --end;
                }
            }
            
            // coner case: duplicate element, 'a'
            ++i;
            while(i < nums.size() - 2 && nums[i] == nums[i - 1]) ++i; 
        }
        
        return ans;
    }
};
