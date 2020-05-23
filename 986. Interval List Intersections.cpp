/* https://leetcode.com/problems/interval-list-intersections/ */

/* Approach 1: merge intervals
Intuition:

Time complexity:  O(n + m)
Space complexity: O(n + m)
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        vector<vector<int>> ans;
        
        int i = 0, j = 0;
        while(i < A.size() && j < B.size())
        {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            
            if(start <= end) ans.push_back(vector<int>({start, end}));
            
            if(A[i][1] < B[j][1])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        
        return ans;
    }
};
