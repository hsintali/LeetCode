/* https://leetcode.com/problems/design-circular-queue/ */

/* Approach 1: Array
Intuition:

Time complexity: O(1)
Space complexity: O(n)
*/

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        capacity = k;
        q = new int[k];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if(isFull()) return false;
        
        rear = (front + size) % capacity;
        q[rear] = value;
        ++size;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if(isEmpty()) return false;
        
        front = (front + 1) % capacity;
        --size;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front()
    {
        return isEmpty()? -1 : q[front];
    }
    
    /** Get the last item from the queue. */
    int Rear()
    {
        return isEmpty()? -1 : q[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return size == capacity;
    }
    
    int capacity;
    int size = 0;
    int *q;
    int front = 0;
    int rear = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
