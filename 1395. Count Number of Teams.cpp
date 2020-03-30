/* https://leetcode.com/problems/count-number-of-teams/ */

/* Approach 1: Brute force
Intuition:

Time complexity: O(n^3)
Space complexity: O(1)
*/

class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int ans = 0;
        
        for(int i = 0; i < rating.size() - 2; ++i)
        {
            for(int j = i + 1; j < rating.size() - 1; ++j)
            {
                for(int k = j + 1; k < rating.size(); ++k)
                {
                    if(rating[i] < rating[j] && rating[j] < rating[k]) ++ans;
                    
                    if(rating[i] > rating[j] && rating[j] > rating[k]) ++ans;
                }
            }
        }
        
        return ans;
    }
};

/* Approach 2: 
Intuition: 選定 j，
           case 1: i < j < k: 若 i < j and rating[i] < rating[j]，找出有 leftSmallerCount 個 i 滿足此條件
                              若 k > j and rating[k] > rating[j]，找出有 rightLargerCount 個 k 滿足此條件
                              因此，滿足 i < j < k 且 rating[i] < rating[j] < rating[k] 共有 leftSmallerCount * rightLargerCount 組。
           case 2: i > j > k: 若 i > j and rating[i] > rating[j]，找出有 leftLargerCount 個 i 滿足此條件
                              若 k < j and rating[k] < rating[j]，找出有 rightSmallerCount 個 k 滿足此條件
                              因此，滿足 i > j > k 且 rating[i] > rating[j] > rating[k] 共有 leftLargerCount * rightSmallerCount 組。         

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int ans = 0;
        
        // i (left) < j < k (right)
        for(int j = 0; j < rating.size(); ++j)
        {
            int leftSmallerCount = 0, leftLargerCount = 0;
            int rightSmallerCount = 0, rightLargerCount = 0;
            
            for(int i = 0; i < j; ++i)
            {
                if(rating[i] < rating[j]) ++leftSmallerCount;
                
                if(rating[i] > rating[j]) ++leftLargerCount;
            }
            
            for(int k = j + 1; k < rating.size(); ++k)
            {
                if(rating[k] < rating[j]) ++rightSmallerCount;
                
                if(rating[k] > rating[j]) ++rightLargerCount;
            }
            
            ans += leftSmallerCount * rightLargerCount + leftLargerCount * rightSmallerCount;
        }
        
        return ans;
    }
};
