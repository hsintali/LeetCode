/* https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/ */

/* Approach 1: hashMap + hashSet + array vector
Intuition: 難點在 remove 中， umap[val], umap[rearVal] 的增刪順序。
           1. 避免 coner case: val == rearVal:
              umap[val].erase(index) 放在 umap[rearVal].insert(index) 之前。
           2. 避免 coner case: remove 最後一個元素，此時 index == nums.size() - 1:
              umap[rearVal].insert(index) 放在 umap[rearVal].erase(nums.size() - 1) 之前。

Time complexity: GetRandom:O(1), Insert and Delete: Amortized O(1)
Space complexity: O(n)
*/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        nums.push_back(val);
        umap[val].insert(nums.size() - 1);
        
        return umap[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        // if val does not exist
        if(umap.count(val) == 0 || umap[val].size() == 0) return false;
        
        int index = *umap[val].begin();        
        int rearVal = nums.back();
                
        // move the last value to index
        nums[index] = rearVal;
        umap[val].erase(index);
        umap[rearVal].insert(index);
        umap[rearVal].erase(nums.size() - 1);  
          
        // remove the last value
        nums.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom()
    {
        int n = nums.size();
        
        if(n == 0) return -1;
        
        return nums[rand() % n];
    }
    
    unordered_map<int, unordered_set<int>> umap;
    vector<int> nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
