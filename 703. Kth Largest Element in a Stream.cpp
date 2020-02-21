/* https://leetcode.com/problems/kth-largest-element-in-a-stream/ */

/* Approach 1: minHeap
Intuition:

Time complexity: KthLargest: O(nlogk); add: O(logk)
Space complexity: O(k)
*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        
        for(auto val : nums)
        {
            if(minHeap.size() < k )
            {
                minHeap.push(val);
            }
            else if(minHeap.size() == k && val > minHeap.top())
            {
                minHeap.push(val);
                minHeap.pop();
            }
        }
    }
    
    int add(int val)
    {
        if(minHeap.size() < k )
        {
            minHeap.push(val);
        }
        else if(minHeap.size() == k && val > minHeap.top())
        {
            minHeap.push(val);
            minHeap.pop();
        }
        
        return minHeap.top();
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
