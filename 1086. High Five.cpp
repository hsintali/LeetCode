/* https://leetcode.com/problems/high-five/ */

/* Approach 1: hashMap + minHeap
Intuition:

Time complexity: O(n + k + klogk), n:# of items, k:# of students, k <= n
Space complexity: O(k)
*/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items)
    {
        vector<vector<int>> ans;
        
        typedef priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int, minHeap> students;
        
        // O(n)
        for(auto &item : items)
        {
            auto &scores = students[item[0]];
            
            scores.push(item[1]);
            if(scores.size() > 5)
            {
                scores.pop();
            }
        }
        
        // O(k)
        for(auto &student : students)
        {
            int sum = 0;
            auto id = student.first;
            auto scores = student.second;
            
            while(!scores.empty())
            {
                sum += scores.top();
                scores.pop();
            }
            
            ans.push_back({student.first, sum / 5});
        }
        
        // O(klogk)
        sort(ans.begin(), ans.end());
        
        return ans; 
    }
};
