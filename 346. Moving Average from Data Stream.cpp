/* https://leetcode.com/problems/moving-average-from-data-stream/ */

/* Approach 1: queue
Intuition: 

Time complexity: O(1)
Space complexity: O(n), where n is the size of the moving window
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        n = size;
    }
    
    double next(int val)
    {
        sum += val;  
        q.push(val);
        
        if(q.size() > n)
        {
            sum -= q.front();
            q.pop();
        }
        
        return (double)sum/q.size();
    }
    
    int n;
    queue<int> q;
    int sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
 
 /* Approach 2: circular array queue
Intuition: 

Time complexity: O(1)
Space complexity: O(n), where n is the size of the moving window
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        length = size + 1;
        queue = new int[length];
    }
    
    double next(int val)
    {
        sum += val;
        
        int tail = (front + count) % length;
        queue[tail] = val;
        ++count;
        
        if(count > length - 1)
        {
            sum -= queue[front];
            front = (front + 1) % length;
            --count;
        }
        
        return (double)sum / count;
    }
    
    int length;
    int *queue;
    int sum = 0;
    int front = 0;
    int count = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
