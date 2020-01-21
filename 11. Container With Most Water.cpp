/* https://leetcode.com/problems/container-with-most-water/ */

/* Approach 1: Two pointer
Intuition: 每次移動第二長的 line，因為移動最長的那條並不會得到更好的結果。
           
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right)
        {
            int width = right - left;
            int length = min(height[left], height[right]);
            maxArea = max(maxArea, width * length);
            
            if(height[left] <= height[right])
            {
                ++left;
            }
            else if(height[left] > height[right])
            {
                --right;
            }
        }
        
        return maxArea;
    }
};
