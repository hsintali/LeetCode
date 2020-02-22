/* https://leetcode.com/problems/top-k-frequent-elements/ */

/* Approach 1: hashMap + maxHeap
Intuition: 先用 hashMap 計算並記錄每個 number 的 frequence。  ==> O(n)
           再將這些 pair push 到 maxHeap 中。                ==> O(nlogn)  (也可用 minHeap ==> O(nlogk))
           最後在 pop 出 k 個最高頻的 number ==> O(klogn)

Time complexity: O(nlogn)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> umap;
        
        for(auto &val : nums)
        {
            ++umap[val];
        }
        
        // pair.first: frequence, pair.second: number
        priority_queue<pair<int, int>> pq;
        
        for(auto &it : umap)
        {
            pq.push({it.second, it.first});
        }
        
        vector<int> ans;
        
        for(int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
