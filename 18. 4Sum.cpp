/* https://leetcode.com/problems/4sum/ */

/* Approach 1: Two pointer + 1 pointer (3sum)
Intuition: 透過 3sum 作為 subroutine，外加一層 for loop 遍歷第四個數。
           假設此數組為 (a, b, c, d) 且 a <= b <= c <= d。使用 i 指針遍歷 nums 找出 a，再用 three sum 找出 b + c + d = a。
           注意
           coner case 1: nums 中可能遇到重複的 a ，需要跳過
           coner case 2: subroutine 3sum 的 coner case 一樣要處理，確保 3sum 回傳的 (b, c, d) 是不會重複的。
           
Time complexity: O(n^3)
Space complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < nums.size() - 3)
        {
            vector<vector<int>> temp_ans = threeSum(nums, i + 1, target - nums[i]);
            
            for(auto three_result : temp_ans)
            {
                three_result.insert(three_result.begin(), nums[i]);
                ans.push_back(three_result);
            }
            
            ++i;
            
            // coner case: duplicate a
            while(i < nums.size() - 3 && nums[i] == nums[i - 1]) ++i;     
        }
        
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int first, int target)
    {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        
        int i = first;
        while(i < nums.size() - 2)
        {
            int start = i + 1;
            int end = nums.size() - 1;
            
            int t = target - nums[i];
            
            while(start < end)
            {
                int sum = nums[start] + nums[end];
                
                if(sum == t)
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    
                    // coner case: more than one c, d
                    ++start;
                    --end;
                    
                    // coner case: duplicate c, d
                    while(start < end && nums[start] == nums[start - 1]) ++start;
                    while(start < end && nums[end] == nums[end + 1]) --end;
                }
                else if(sum < t)
                {
                    ++start;
                }
                else if(sum > t)
                {
                    --end;
                }
            }
            
            ++i;
            
            // coner case: duplicate b
            while(i < nums.size() - 2 && nums[i] == nums[i - 1]) ++i;     
        }
        
        return ans;
    }
};

/* Approach 2: Two pointer (2sum)
Intuition: 透過 2sum 作為 subroutine，分別使用 2sum 找出 (a, b) 並存下來，然後找出 (c, d) 使得 (a + b) = target - (c + d)。
           
Time complexity: O(n^2)
Space complexity: O(n)
*/
