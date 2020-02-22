/* https://leetcode.com/problems/last-stone-weight/ */

/* Approach 1: maxHeap
Intuition:

Time complexity: O(nlogn)
Space complexity: O(n)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> maxHeap;
        
        for(auto &stone : stones)
        {
            maxHeap.push(stone);
        }
        
        while(maxHeap.size() >= 2)
        {
            int first = maxHeap.top();
            maxHeap.pop();
            
            int second = maxHeap.top();
            maxHeap.pop();
            
            maxHeap.push(first - second);
        }
        
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

/* Approach 2: Buckets
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        vector<int> buckets(1001, 0);
        
        for(auto &stone : stones)
        {
            ++buckets[stone];
        }
        
        int w = buckets.size() - 1;
        int firstLargest = 0;
        
        while(buckets[w] != 0 || w >= 1)
        {
            if(firstLargest == 0) buckets[w] %= 2;
            
            if(buckets[w] == 0)
            {
                --w;
                continue;
            }
            
            if(firstLargest == 0)
            {
                firstLargest = w;
                --buckets[w--];
            }
            else
            {
                int secondLargest = w;
                --buckets[w];

                int diff = firstLargest - secondLargest;
                                
                ++buckets[diff];
                
                firstLargest = (diff > w)? diff : 0;
            }
        }
        
        return firstLargest;
    }
};
