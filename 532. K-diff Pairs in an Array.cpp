/* https://leetcode.com/problems/k-diff-pairs-in-an-array/ */

/* Approach 1: Set
Intuition: Per set.insert() costs O(log n) time.

Time complexity:  O(n^2 * logn)
Space complexity: O(n^2)
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        set<pair<int, int>> pairs;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(abs(nums[i] - nums[j]) == k)
                {
                    if(nums[i] <= nums[j])
                    {
                        pairs.insert(make_pair(nums[i], nums[j]));
                    }
                    else
                    {
                        pairs.insert(make_pair(nums[j], nums[i]));
                    }
                }
            }
        }
        
        return pairs.size();
    }
};

/* Approach 2: hashMap
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        if(k < 0) return 0;
        
        unordered_map<int, int> umap;
        int count{};
        
        for(auto &n : nums)
        {
            ++umap[n];
        }
        
        for(auto it : umap)
        {
            if(k == 0 && it.second >= 2) ++count;
            if(k > 0 && umap.count(it.first + k) > 0) ++count;
        }
        
        return count;
    }
};
