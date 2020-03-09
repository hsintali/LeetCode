/* https://leetcode.com/problems/word-ladder-ii/ */

/* Approach 2: BFS
Intuition: 把每次找過的 word 都存在 queue 中。

Time complexity: O(N * L^2), where L is the length of words and N is the total number of words in the input word list
Space complexity: O(N * (N * L))
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict;
        for(auto &word : wordList)
        {
            dict.insert(word);
        }
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        queue<vector<string>> que;
        que.push({beginWord});
        dict.erase(beginWord);
        
        vector<vector<string>> ans;
        
        bool isFound = false;
        
        // O(N)
        while(!que.empty())
        {
            int size = que.size();         
            for(int num = 0; num < size; ++num)
            {
                vector<string> cur = que.front();
                que.pop();
                vector<string> nextWords = getNext(cur.back(), dict);
                
                for(auto &nextWord : nextWords)
                {
                    vector<string> newList = cur;
                    newList.push_back(nextWord);
                    
                    visited.insert(nextWord);
                    que.push(newList);
                    
                    if(nextWord == endWord)
                    {
                        ans.push_back(newList);
                        isFound = true;
                    }
                }
            }
            
            if(isFound) break;
            
            for(auto &word : visited)
            {
                dict.erase(word);
            }
        }
        
        return ans;
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
                }
            }
            
            word[i] = c;
        }
        
        return res;
    }
};
