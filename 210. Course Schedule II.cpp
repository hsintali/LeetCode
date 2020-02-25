/* https://leetcode.com/problems/course-schedule-ii/ */

/* Approach 1: Topological Sorting
Intuition:

Time complexity: O(V + E)
Space complexity: O(V + E)
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> inDegree(numCourses, 0);
        
        vector<vector<int>> neighbors(numCourses, vector<int>());
        
        // get in-degree
        for(auto &prerequisite : prerequisites)
        {
            // prerequisite[i, j]: j -> i
            neighbors[prerequisite[1]].push_back(prerequisite[0]);
            ++inDegree[prerequisite[0]];
        }
        
        queue<int> que;
        
        // put nodes with zero in-degree 
        for(int i = 0; i < numCourses; ++i)
        {
            if(inDegree[i] == 0)
            {
                que.push(i);
            }
        }
        
        vector<int> courses;
        
        // BFS
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            courses.push_back(cur);
            
            for(auto &neighbor : neighbors[cur])
            {
                --inDegree[neighbor];
                
                if(inDegree[neighbor] == 0)
                {
                    que.push(neighbor);
                }
            }
        }
        
        return courses.size() == numCourses ? courses : vector<int>();
    }
};
