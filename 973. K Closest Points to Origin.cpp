/* https://leetcode.com/problems/k-closest-points-to-origin/ */

/* Approach 1: sort
Intuition:

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
             }
        );
        
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

/* Approach 2: hashMap + maxHeap
Intuition:

Time complexity: O(nlogk)
Space complexity: O(k)
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        unordered_map<int, int> umap; // key:index, val:distance
        
        // O(n)
        for(int i = 0; i < points.size(); ++i)
        {
            umap[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        }
        
        // pair.first:distance, pair.second: index
        priority_queue<pair<int, int>> maxHeap;
        
        // O(nlogk)
        for(auto &point : umap)
        {
            maxHeap.push(make_pair(point.second, point.first));
            
            if(maxHeap.size() > K)
            {
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        // O(klogk)
        for(int i = 0; i < K; ++i)
        {
            int index = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(points[index]);
        }
        
        return ans;
    }
};

/* Approach 3: Quick Select
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/
