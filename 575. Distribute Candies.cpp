/* https://leetcode.com/problems/distribute-candies/ */

/* Approach 1: Hash
Intuition: 可能拿到的種類是 maxKinds = candies.size() / 2;
           希望能拿到最多的種類: 把新的種類給 sisiter，重複的種類給 brother
                               ==> 遍歷 candies，當遇到新的種類時 ++count，但最多只能拿到 maxKinds 種。

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int distributeCandies(vector<int>& candies)
    {        
        if(candies.size() == 0) return 0;
        
        int maxKinds = candies.size() / 2;
        int kinds[200001] = {0};
        int count = 0;
        
        for(auto & candy : candies)
        {
            ++kinds[candy + 100000];
            if(kinds[candy + 100000] == 1)
            {
                ++count;
            }
        }
        
        return count > maxKinds ? maxKinds : count;
    }
};

/* Approach 2: Sort
Intuition: 

Time complexity: O(nlogn)
Space complexity: O(1)
*/

class Solution {
public:
    int distributeCandies(vector<int>& candies)
    {        
        if(candies.size() == 0) return 0;
        
        int maxKinds = candies.size() / 2;
        int count = 1;
        
        sort(candies.begin(), candies.end());
        
        for(int i = 1; i < candies.size(); ++i)
        {
            if(candies[i] != candies[i - 1])
            {
                ++count;
            }
            
            if(count >= maxKinds) break;
        }
        
        return count > maxKinds ? maxKinds : count;
    }
};
