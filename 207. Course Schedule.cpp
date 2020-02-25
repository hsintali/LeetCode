/* https://leetcode.com/problems/course-schedule/ */

/* Approach 1: Topological Sorting
Intuition:

Time complexity: O(V + E)
Space complexity: O(V + E)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> inDegree(numCourses, 0);
        
        vector<vector<int>> neighbors(numCourses, vector<int>());
        
        // Get in-degree
        for(auto &prerequisite : prerequisites)
        {
            // prerequisite[i, j]: j -> i
            neighbors[prerequisite[1]].push_back(prerequisite[0]);
            ++inDegree[prerequisite[0]];
        }
        
        queue<int> que;
        
        // Find the start nodes
        for(int i = 0; i < numCourses; ++i)
        {
            if(inDegree[i] == 0)
            {
                que.push(i);
            }
        }
        
        int courses = 0;
        
        // Topological sort
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            ++courses;
            
            for(auto &neighbor : neighbors[cur])
            {
                --inDegree[neighbor];
                
                if(inDegree[neighbor] == 0)
                {
                    que.push(neighbor);
                }
            }
        }
        
        return courses == numCourses;
    }
};
