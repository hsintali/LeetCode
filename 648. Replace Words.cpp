/* https://leetcode.com/problems/replace-words/ */

/* Approach 1: Trie
Intuition:
Time complexity:  O(n), the length of sentence
Space complexity: O(T), the size of trie
*/

class Trie
{
public:
    Trie()
    {
        children = new Trie*[26];
        
        for(int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
        
        isRoot = false;
    }
    
    void insert(string word)
    {
        Trie *node = this;
        for(auto &c : word)
        {
            if(node->children[c - 'a'] == nullptr) node->children[c - 'a'] = new Trie;
            
            node = node->children[c - 'a'];
        }
        
        node->isRoot = true;
        node->word = word;
    }
    
    string search(string word)
    {
        Trie *node = this;
        for(auto &c : word)
        {
            if(node->children[c - 'a'] == nullptr) return word;
            
            node = node->children[c - 'a'];
            
            if(node->isRoot == true)
            {
                return node->word;
            }
        }
        
        return word;
    }
    
    Trie **children;
    bool isRoot;
    string word;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence)
    {
        Trie trie;
        
        for(auto word : dict)
        {
            trie.insert(word);
        }
        
        string ans = "";
        int lastIndex = 0;
        for(int i = 0; i <= sentence.size(); ++i)
        {
            if(sentence[i] == ' ')
            {
                ans += trie.search(sentence.substr(lastIndex, i - lastIndex)) + " ";
                lastIndex = i + 1;
            }
            else if(i == sentence.size())
            {
                ans += trie.search(sentence.substr(lastIndex, i - lastIndex));
            }
        }
        
        return ans;
    }
};
