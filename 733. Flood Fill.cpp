/* https://leetcode.com/problems/flood-fill/ */

/* Approach 1: BFS
Intuition:

Time complexity:  O(V) = O(n)
Space complexity: O(V + E) = O(n)
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        
        int target = image[sr][sc];
        if(target == newColor) return image;
        image[sr][sc] = newColor;
        
        queue<pair<int, int>> que;
        que.push(make_pair(sr, sc));
        
        int DIR_X[4] = {1, -1, 0, 0};
        int DIR_Y[4] = {0, 0, 1, -1};
                
        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
                        
            for(int i = 0; i < 4; ++i)
            {
                int new_x = x + DIR_X[i];
                int new_y = y + DIR_Y[i];
                
                if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
                if(image[new_x][new_y] != target) continue;
                
                que.push(make_pair(new_x, new_y));
                image[new_x][new_y] = newColor;
            }
        }
        
        return image;
    }
};

/* Approach 2: DFS
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int target = image[sr][sc];
        
        if(target == newColor) return image;
        
        dfs(image, sr, sc, target, newColor);
        
        return image;
    }
    
    void dfs(vector<vector<int>> &image, int x, int y, int target, int newColor)
    {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) return;
        if(image[x][y] != target) return;
        
        image[x][y] = newColor;
        
        dfs(image, x + 1, y, target, newColor);
        dfs(image, x - 1, y, target, newColor);
        dfs(image, x, y + 1, target, newColor);
        dfs(image, x, y - 1, target, newColor);
    }
};
