/* https://leetcode.com/problems/insert-delete-getrandom-o1/ */

/* Approach 1: hashMap + array vector
Intuition:

Time complexity: GetRandom:O(1), Insert and Delete: Amortized O(1)
Space complexity: O(n)
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        // if val already exists
        if(umap.count(val) != 0) return false;
        
        // key = val : value = index of val in nums
        nums.push_back(val);
        umap[val] = nums.size() - 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        // if val dose not exist
        if(umap.count(val) == 0) return false;

        int index = umap[val];
        int rearVal = nums[nums.size() - 1];
        
        // move the last value to index
        umap[rearVal] = index;
        nums[index] = rearVal;
        
        // remove the last value
        umap.erase(val);        
        nums.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        int n = nums.size();
        if(n == 0) return INT_MIN;
        
        return nums[rand() % n];
    }
    
    unordered_map<int, int> umap;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
