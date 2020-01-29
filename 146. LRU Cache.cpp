/* https://leetcode.com/problems/lru-cache/ */

/* Approach 1: hashMap + list
Intuition: 注意: put() 時，若 Key 已經存在，則直接更改其 value 並改變其在 cache 的位置。
                          若 key 不存在，cache 未滿時直接插入，若滿了，則要刪除最前面的 Least Recently Used {key, value}。

Time complexity: O(1)
Space complexity: O(capacity)
*/

class LRUCache {
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    
    int get(int key)
    {
        if(hashMap.count(key) == 1)
        {
            int val = hashMap.at(key)->second;
            cache.erase(hashMap.at(key));
            
            cache.push_back({key, val});
            hashMap[key] = --cache.end();
            
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value)
    {
        if(get(key) != -1)
        {
            hashMap[key]->second = value;
            return;
        }
        
        cache.push_back({key, value});      
        hashMap[key] = --cache.end();
        
        if(hashMap.size() > capacity)
        {
            int head = cache.front().first;
            hashMap.erase(head);
            cache.pop_front();
        }
    }
    
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator> hashMap;
    list<pair<int,int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* Approach 2: hashMap + double linked list
Intuition: 注意: put() 時，若 Key 已經存在，則直接更改其 value 並改變其在 cache 的位置。
                          若 key 不存在，cache 未滿時直接插入，若滿了，則要刪除最前面的 Least Recently Used {key, value}。

Time complexity: O(1)
Space complexity: O(capacity)
*/

class DLNode {
public:
    int key;
    int value;
    DLNode *next;
    DLNode *pre;
    
    DLNode(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
        pre = NULL;
    }
};

class LRUCache {
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        front = new DLNode(-1, -1);
        rear = new DLNode(-1, -1);
        front->next = rear;
        rear->pre = front;
    }
    
    int get(int key)
    {
        if(hashMap.count(key) == 0) return -1;
        
        DLNode *node = hashMap[key];
        moveToRear(node);

        return node->value;
    }
    
    void put(int key, int value)
    {
        if(get(key) != -1)
        {
            hashMap[key]->value = value;

            return;
        }
        
        DLNode *node = new DLNode(key, value);
        push_back(node);

        if(hashMap.size() > capacity) 
        {
            pop_front();
        }
    }
    
    void push_back(DLNode *&node)
    {
        node->pre = rear->pre;
        rear->pre->next = node;
        rear->pre = node;
        node->next = rear;
        hashMap[node->key] = node;
    }
    
    void pop_front()
    {
        DLNode *node = front->next;
        front->next = node->next;
        front->next->pre = front;
        hashMap.erase(node->key);
        delete node;
    }
    
    void moveToRear(DLNode *&node) // move node to be the rear
    {
        // link node->pre and node->next
        node->pre->next = node->next;
        node->next->pre = node->pre;
        
        // add before rear
        node->pre = rear->pre;
        rear->pre->next = node;
        node->next = rear;
        rear->pre = node;
    }
    
    int capacity;
    unordered_map<int, DLNode*> hashMap;
    DLNode *front;
    DLNode *rear;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
