/* https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/ */

/* Approach 1: two pointer
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        if(numbers.size() < 2) return vector<int>({0, 0});
        
        int left = 0, right = numbers.size() - 1;
        
        while(left < right)
        {
            if(numbers[left] + numbers[right] == target)
            {
                return vector<int>({left + 1, right + 1});
            }
            else if(numbers[left] + numbers[right] < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        
        return vector<int>({0, 0});
    }
};
