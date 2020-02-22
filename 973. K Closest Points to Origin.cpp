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

/* Approach 2: hashMap + minHeap
Intuition:
Time complexity: 
Space complexity: O(k)
*/
