/* https://leetcode.com/problems/find-lucky-integer-in-an-array/ */

/* Approach 1: hashMap
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int findLucky(vector<int>& arr)
    {
        unordered_map<int, int> umap;
        
        for(auto &a : arr)
        {
            ++umap[a];
        }
        
        int maxLucky = -1;
        
        for(auto &it : umap)
        {
            if(it.first == it.second)
            {
                if(it.first > maxLucky) maxLucky = it.first;
            }
        }
        
        return maxLucky;
    }
};
