/* https://leetcode.com/problems/min-stack/ */

/* Approach 1: 2 stack
Intuition: 1 個 mainStack  存放所有 value，
           1 個 minStack 當遇到最小值時，push 進去。

Time complexity: O(1)
Space complexity: O(n)
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {
        
    }
    
    void push(int x)
    {
        if(minStack.empty() || x <= getMin())
        {
            minStack.push(x);
        }
        
        mainStack.push(x);
    }
    
    void pop()
    {
        if(getMin() == mainStack.top())
        {
            minStack.pop();
        }
        
        mainStack.pop();
    }
    
    int top()
    {
        return mainStack.top();
    }
    
    int getMin()
    {
        return minStack.top();
    }
    
    stack<int> mainStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 /* Approach 1: 1 stack + pair

Time complexity: O(1)
Space complexity: O(n)
*/

