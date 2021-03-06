/* https://leetcode.com/problems/flatten-nested-list-iterator/ */

/* Approach 1: recursive
Intuition:

Time complexity:  O()
Space complexity: O()
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    void unpack(vector<NestedInteger> &nestedList)
    {
        for(auto &list : nestedList)
        {
            if(list.isInteger())
            {
                que.push(list.getInteger());
            }
            else
            {
                unpack(list.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        unpack(nestedList);
    }
    
    int next()
    {
        int val = que.front();
        que.pop();
        return val;
    }
    
    bool hasNext()
    {
        return !que.empty();
    }
    
    queue<int> que; 
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/* Approach 2: iterative by stack
Intuition:

Time complexity:  O()
Space complexity: O()
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for(int i = nestedList.size() - 1; i >= 0; --i)
        {
            stk.push(&nestedList[i]);
        }
    }
    
    int next()
    {
        int val = stk.top()->getInteger();
        stk.pop();
        return val;
    }
    
    bool hasNext()
    {
        while(!stk.empty())
        {
            NestedInteger *top = stk.top();
            
            if(top->isInteger()) return true;
            
            stk.pop();
            
            vector<NestedInteger> &topList = top->getList();
            for(int i = topList.size() - 1; i >= 0; --i)
            {
                stk.push(&topList[i]);
            }
        }
        
        return false;
    }
    
    stack<NestedInteger*> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
