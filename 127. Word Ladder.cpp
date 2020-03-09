/* https://leetcode.com/problems/word-ladder/ */

/* Approach 1: BFS
Intuition: 

Time complexity: O(N^2 * L), where L is the length of words and N is the total number of words in the input word list
Space complexity: O(N * L)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        queue<string> que;
        que.push(beginWord);
        
        // O(N)
        for(int steps = 2; !que.empty(); ++steps)
        {
            int size = que.size();
            
            for(int num = 0; num < size; ++num)
            {
                string cur = que.front();
                que.pop();
                vector<string> nextWords = getNext(cur, wordList);
                
                for(auto &nextWord : nextWords)
                {
                    if(visited.count(nextWord) == 1) continue;
                    
                    if(nextWord == endWord) return steps;
                    
                    que.push(nextWord);
                    visited.insert(nextWord);
                }
            }
        }
        
        return 0;
    }
    
    // O(NL)
    vector<string> getNext(string s, vector<string> &wordList)
    {
        vector<string> res;
        
        // O(N)
        for(auto &word : wordList)
        {
            int diff = 0;
            
            // O(L)
            for(int i = 0; i < word.size(); ++i)
            {
                if(s[i] != word[i]) ++diff;
            }
            
            // O(L)
            if(diff == 1) res.push_back(word);
        }
        
        return res;
    }
};

/* Approach 1-2: BFS
Intuition: 

Time complexity: Amortized O(N * L), where L is the length of words and N is the total number of words in the input word list
Space complexity: O(N * L)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict;
        for(auto &word : wordList)
        {
            dict.insert(word);
        }
        
        queue<string> que;
        que.push(beginWord);
        
        // O(N)
        for(int steps = 2; !que.empty(); ++steps)
        {
            int size = que.size();
            
            for(int num = 0; num < size; ++num)
            {
                string cur = que.front();
                que.pop();
                vector<string> nextWords = getNext(cur, dict);
                
                for(auto &nextWord : nextWords)
                {                    
                    if(nextWord == endWord) return steps;
                    
                    que.push(nextWord);
                }
            }
        }
        
        return 0;
    }
    
    // O(NL / N)
    vector<string> getNext(string s, unordered_set<string> &dict)
    {
        vector<string> res;
        
        // O(< N)
        for(auto it = dict.begin(); it != dict.end(); )
        {
            auto word = *it;
            int diff = 0;
            
            // O(L)
            for(int i = 0; i < word.size(); ++i)
            {
                if(s[i] != word[i]) ++diff;
                if(diff > 1) break;
            }
            
            // O(L)
            if(diff == 1)
            {
                res.push_back(word);
                it = dict.erase(it);
            }
            else
            {
                ++it;
            }
        }
        
        return res;
    }
};

/* Approach 2: BFS
Intuition: 

Time complexity: O(N * L^2), where L is the length of words and N is the total number of words in the input word list
Space complexity: O(N * L)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict;
        for(auto &word : wordList)
        {
            dict.insert(word);
        }
        
        queue<string> que;
        que.push(beginWord);
        dict.erase(beginWord);
        
        // O(N)
        for(int steps = 2; !que.empty(); ++steps)
        {
            int size = que.size();
            
            for(int num = 0; num < size; ++num)
            {
                string cur = que.front();
                que.pop();
                vector<string> nextWords = getNext(cur, dict);
                
                for(auto &nextWord : nextWords)
                {                    
                    if(nextWord == endWord) return steps;
                    
                    que.push(nextWord);
                }
            }
        }
        
        return 0;
    }
    
    // O(26 * L^2)
    vector<string> getNext(string word, unordered_set<string> &dict)
    {
        vector<string> res;
        
        // O(L)
        for(int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            
            // O(26)
            for(int j = 0; j < 26; ++j)
            {
                word[i] = 'a' + j;
                
                if(dict.count(word) == 1)
                {
                    res.push_back(word); // O(L)
                    dict.erase(word);    // O(1)
                }
            }
            
            word[i] = c;
        }
        
        return res;
    }
};
