/* https://leetcode.com/problems/implement-queue-using-stacks/ */

/* Approach 1: 2 stack
Intuition: front 用來存 當 stack_in 為空時，第一個放進去的值，
           這樣，當 stack_out pop 到空的時候，才知道當前的 top 值。

Time complexity:  push() :O(1)
                  pop()  :Amortized: O(1), Worst-case: O(n)
                  peak() :O(1)
                  empty():O(1)
Space complexity: push() :O(n)
                  pop()  :O(1)
                  peak() :O(1)
                  empty():O(1)
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        if(stack_in.empty())
        {
            front = x;
        }
        
        stack_in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if(stack_out.empty())
        {
            while(!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        
        int val = stack_out.top();
        stack_out.pop();
        
        return val;
    }
    
    /** Get the front element. */
    int peek()
    {
        if(stack_out.empty())
        {
            return front;
        }
        
        return stack_out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stack_in.empty() && stack_out.empty();
    }
    
    stack<int> stack_in, stack_out;
    int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
