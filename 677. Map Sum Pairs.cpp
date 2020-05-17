/* https://leetcode.com/problems/map-sum-pairs/ */

/* Approach 1: Trie
Intuition:
Time complexity:  insert: O(n), sum: O(n), where m is the word/prefix length.
Space complexity: insert: O(n), sum: O(1)
*/

class TrieNode
{
public:
    TrieNode **children;
    int sumVal;

    TrieNode()
    {
        children = new TrieNode*[26];
        
        for(int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;  
        }
        
        sumVal = 0;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum()
    {
        root = new TrieNode;
    }
    
    void insert(string key, int val)
    { 
        TrieNode *node = root;
        
        for(auto &c : key)
        {
            if(node->children[c -'a'] == nullptr) node->children[c -'a'] = new TrieNode;
            
            node = node->children[c -'a'];
            node->sumVal += val - mapping[key];
        }
        
        mapping[key] = val;
    }
    
    int sum(string prefix)
    {
        TrieNode *node = root;   
        for(auto &c : prefix)
        {
            if(node->children[c -'a'] == nullptr) return 0;
            
            node = node->children[c -'a'];
        }
        
        return node->sumVal;
    }
    
    TrieNode *root;
    unordered_map<string, int> mapping;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
