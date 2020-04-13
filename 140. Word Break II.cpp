/* https://leetcode.com/problems/word-break-ii/ */

/* Approach 1: DFS + Memorization
Intuition:

Time complexity:O(n^3)
Space complexity: O(n^3)
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> dict;
        dict.insert(wordDict.begin(), wordDict.end());
        
        unordered_map<int, vector<string>> memo;
        
        return dfs(s, dict, 0, memo);
    }
    
    vector<string> dfs(string &s, unordered_set<string> &dict, int start, unordered_map<int, vector<string>> &memo)
    {
        vector<string> result;
        
        if(start == s.size())
        {
            result.push_back("");
            return result;
        }

        if(memo.count(start) == 1) return memo[start];
        
        for(int end = start; end < s.size(); ++end)
        {
            string word = s.substr(start, end - start + 1);
            if(dict.find(word) != dict.end())
            {
                vector<string> wordList = dfs(s, dict, end + 1, memo);
                
                for(int i = 0; i < wordList.size(); ++i)
                {
                    string subList = word;
                    if(wordList[i] != "") subList += " " + wordList[i];
                    result.push_back(subList);
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};

/* Approach 1-2: DFS + Memorization (Improved)
Intuition: 超過 wordDict 中最長的單字長度就退出。

Time complexity:O(n^3)
Space complexity: O(n^3)
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> dict;
        dict.insert(wordDict.begin(), wordDict.end());
        
        size_t maxLen = 0;
        for(auto &word : wordDict)
        {
            maxLen = max(maxLen, word.length());
        }
        
        unordered_map<int, vector<string>> memo;
        
        return dfs(s, dict, 0, memo, maxLen);
    }
    
    vector<string> dfs(string &s, unordered_set<string> &dict, int start, unordered_map<int, vector<string>> &memo, size_t &maxLen)
    {
        vector<string> result;
        
        if(start == s.size())
        {
            result.push_back("");
            return result;
        }

        if(memo.count(start) == 1) return memo[start];
        
        for(int end = start; end < s.size(); ++end)
        {
            if(end - start + 1 > maxLen) break;
            
            string word = s.substr(start, end - start + 1);
            if(dict.find(word) != dict.end())
            {
                vector<string> wordList = dfs(s, dict, end + 1, memo, maxLen);
                
                for(int i = 0; i < wordList.size(); ++i)
                {
                    string subList = word;
                    if(wordList[i] != "") subList += " " + wordList[i];
                    result.push_back(subList);
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};
