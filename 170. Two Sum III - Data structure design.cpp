/* https://leetcode.com/problems/two-sum-iii-data-structure-design/ */

/* Approach 1: hash 
Intuition: 建立 hash map, add 時直接加入。find 時，遍歷所有 entry，找出相對應的值是否存在。
           for(auto pair : hashMap): 這裡的 pair 是一個 pair，可算是 reference 版本的 iterator => pair.first, pair.second。
           若是 for(auto elem : hashSet): 這裡的 elem 是一個 element，可算是 reference 版本的 iterator。
           
Time complexity: add:O(1), find:O(n)
Space complexity: O(n)
*/

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum()
    {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        if(hashMap.find(number) == hashMap.end())
        {
            hashMap[number] = 1;
        }
        else
        {
            ++hashMap[number];
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        for(auto pair : hashMap)
        {
            int diff = value - pair.first;
            if(hashMap.find(diff) != hashMap.end())
            {
                if(diff != pair.first)
                {
                    return true;
                }
                else if(diff == pair.first && hashMap[diff] > 1)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    unordered_map<int, int> hashMap;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
