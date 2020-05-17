/* https://leetcode.com/problems/implement-trie-prefix-tree/ */

/* Approach 1: Trie 模板題
Intuition:

Time complexity:  insert: O(n), search/startsWith: O(n), where m is the word/prefix length.
Space complexity: insert: O(n), search/startsWith: O(1)
*/

class TrieNode
{
public:
    TrieNode **children;
    bool isWord;

    TrieNode()
    {
        children = new TrieNode*[26];
        
        for(int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;  
        }
        
        isWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        
        for(auto &c : word)
        {
            if(node->children[c - 'a'] == nullptr)
            {
                node->children[c - 'a'] = new TrieNode;
            }
            
            node = node->children[c - 'a'];
        }
        
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = root;
        
        for(auto &c : word)
        {
            if(node->children[c - 'a'] == nullptr) return false;
            
            node = node->children[c - 'a'];
        }
        
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        
        for(auto &c : prefix)
        {
            if(node->children[c - 'a'] == nullptr) return false;
            
            node = node->children[c - 'a'];
        }
        
        return true;
    }
    
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 
 /* Approach 2: 合併 TrieNode 到 Trie 裡面
Intuition:

Time complexity:  insert: O(n), search/startsWith: O(n), where m is the word/prefix length.
Space complexity: insert: O(n), search/startsWith: O(1)
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
    {
        children = new Trie*[26];
        
        for(int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;  
        }
        
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        
        for(auto &c : word)
        {
            if(node->children[c - 'a'] == nullptr)
            {
                node->children[c - 'a'] = new Trie;
            }
            
            node = node->children[c - 'a'];
        }
        
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = this;
        
        for(auto &c : word)
        {
            if(node->children[c - 'a'] == nullptr) return false;
            
            node = node->children[c - 'a'];
        }
        
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *node = this;
        
        for(auto &c : prefix)
        {
            if(node->children[c - 'a'] == nullptr) return false;
            
            node = node->children[c - 'a'];
        }
        
        return true;
    }
    
    Trie **children;
    bool isWord;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
