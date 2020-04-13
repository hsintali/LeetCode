/* https://leetcode.com/problems/contiguous-array/ */

/* Approach 1: Bruteforce
Intuition:

Time complexity:O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {        
        int ans = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int count[2]= {0, 0};   
            for(int j = i; j < nums.size(); ++j)
            {
                if(nums[j] == 0)
                {
                    ++count[0];
                }
                else
                {
                    ++count[1];
                }

                if(count[0] == count[1])
                {
                    ans = max(ans, 2 * count[0]);
                }
            }
        }
        
        return ans;
    }
};

/* Approach 2: HashMap
Intuition: 用 HashMap 紀錄 0, 1 相差的數量最早發生時的 index。
           例如，在 i=5 時 0 比 1 多 2，所以 umap[2]=5，
           下次 0 又比 1 多 2 時發生在 i=11，則代表從 i=6,7,8,9,10,11 的這個區間 0, 1 的數量是相等的。

Time complexity:O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        // {count: index}
        unordered_map<int, int> umap;
        umap[0] = -1;
        
        int ans = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            count += (nums[i] == 0) ? 1 : -1;
            
            if(umap.count(count) == 1)
            {
                ans = max(ans, i - umap[count]);
            }
            
            else
            {
                umap[count] = i;
            }
        }
        
        return ans;
    }
};
