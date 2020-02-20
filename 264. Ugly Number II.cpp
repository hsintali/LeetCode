/* https://leetcode.com/problems/ugly-number-ii/ */

/* Approach 1: heap
Intuition:

Time complexity: O(nlogn)
Space complexity: O(n)
*/

class Solution {
public:
    int nthUglyNumber(int n)
    {
        priority_queue<long long, vector<long long>, std::greater<long long>> pqueue;
        unordered_set<long long> uset = {1};
        int multi[3] = {2, 3, 5};
        
        pqueue.push(1);
        long long val = 1;
        
        for(int i = 0; i < n; ++i)
        {
            val = pqueue.top();
            pqueue.pop();
            
            for(auto m : multi)
            {
                long long uglyNumber = val * m;
                
                if(uset.count(uglyNumber) == 0)
                {
                    pqueue.push(uglyNumber);
                    uset.insert(uglyNumber);
                }
            }
        }
        
        return val;
    }
};

/* Approach 2: DP
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/
