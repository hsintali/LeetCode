/* https://leetcode.com/problems/shuffle-an-array/ */

/* Approach 1: Fisher–Yates Shuffle
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    Solution(vector<int>& nums)
    {
        srand(time(NULL));
        originalArr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return originalArr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> newArr = originalArr;
        
        for(int i = 0; i < newArr.size(); ++i)
        {
            int index = rand() % (newArr.size() - i);
            int temp = newArr[i];
            newArr[i] = newArr[index + i];
            newArr[index + i] = temp;
        }
        
        return newArr;
    }
    
    vector<int> originalArr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
