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
 
 /* Approach 2: 1 stack + pair
Intuition: 用 pair 存放 val 及當下最小值
           
Time complexity: O(1)
Space complexity: O(n)
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {
        soFarMin = INT_MAX;
    }
    
    void push(int x)
    {
        soFarMin = min(soFarMin, x);
        stack_.push({x, soFarMin});
    }
    
    void pop()
    {
        stack_.pop();
        
        if(!stack_.empty())
        {
            soFarMin = stack_.top().second;
        }
        else
        {
            soFarMin = INT_MAX;
        }
    }
    
    int top()
    {
        return stack_.top().first;
    }
    
    int getMin()
    {
        return stack_.top().second;
    }
    
    stack<pair<int, int>> stack_;
    int soFarMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
