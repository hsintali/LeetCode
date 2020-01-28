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
        if(hashMap.count(key) == 1)
        {
            cache.erase(hashMap.at(key));
            
            cache.push_back({key, value});
            hashMap[key] = --cache.end();
            return;
        }
        
        if(hashMap.size() < capacity)
        {
            cache.push_back({key, value});
            hashMap[key] = --cache.end();
        }
        else
        {
            int head = cache.front().first;
            hashMap.erase(head);
            cache.pop_front();
            
            cache.push_back({key, value});
            hashMap[key] = --cache.end();
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
