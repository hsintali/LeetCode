/* https://leetcode.com/problems/design-circular-deque/ */

/* Approach 1: Array
Intuition: 注意:
           1. insertFront: front = (front + capacity - 1) % capacity; 要 + capacity，
              因為若 front = 0 時, front - 1 % capacity 會是 -1, out of index。
              deleteLast 一樣道理。
           2. insertFront 時，要記得更新 rear = (front + size - 1) % capacity，
              否則 rear 有可能會指向錯誤的地方。

Time complexity: O(1)
Space complexity: O(n)
*/

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        capacity = k;
        q = new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if(isFull()) return false;

        front = (front + capacity - 1) % capacity;
        q[front] = value;
        ++size;
        rear = (front + size - 1) % capacity;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if(isFull()) return false;

        rear = (front + size) % capacity;
        q[rear] = value;
        ++size;

        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if(isEmpty()) return false;

        front = (front + 1) % capacity;
        --size;

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if(isEmpty()) return false;

        rear = (rear + capacity - 1) % capacity;
        --size;

        return true;   
    }
    
    /** Get the front item from the deque. */
    int getFront()
    {
        return isEmpty()? -1 : q[front];
    }
    
    /** Get the last item from the deque. */
    int getRear()
    {
        return isEmpty()? -1 : q[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
