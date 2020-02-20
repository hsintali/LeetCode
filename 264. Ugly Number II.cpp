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

class Solution {
public:
    int nthUglyNumber(int n)
    {
        if(n == 1) return 1;
        
        vector<int> uglyNumbers(n, 0);
        uglyNumbers[0] = 1;
        
        int p2 = 0, p3 = 0, p5 = 0;
        
        for(int i = 1; i < n; ++i)
        {
            uglyNumbers[i] = min(uglyNumbers[p2] * 2, min(uglyNumbers[p3] * 3, uglyNumbers[p5] * 5));
            
            if(uglyNumbers[i] == uglyNumbers[p2] * 2) ++p2;
            if(uglyNumbers[i] == uglyNumbers[p3] * 3) ++p3;
            if(uglyNumbers[i] == uglyNumbers[p5] * 5) ++p5;
        }
        
        return uglyNumbers.back();
    }
};
