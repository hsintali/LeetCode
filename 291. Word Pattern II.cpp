/* https://leetcode.com/problems/word-pattern-ii/ */

/* Approach 1: DFS
Intuition:
Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str)
    {
        
        unordered_map<char, string> mapping;
        unordered_map<string, char> used;
        
        return dfs(pattern, 0, str, 0, mapping, used);
    }
    
    bool dfs(string &pattern, int i,
             string &str, int j,
             unordered_map<char, string> &mapping, unordered_map<string, char> &used)
    {
        if(i == pattern.size() || j == str.size()) return i == pattern.size() && j == str.size();
        
        if(mapping.count(pattern[i]) == 1)
        {
            string word = mapping[pattern[i]];
            if(str.substr(j, word.size()) != word) return false;
            return dfs(pattern, i + 1, str, j + word.size(), mapping, used);
        }
        
        // if pattern[i] has no mapping string yet
        for(int len = 1; j + len - 1 < str.size(); ++len)
        {
            string word = str.substr(j, len);
            
            if(used.count(word) == 1) continue;
            
            mapping[pattern[i]] = word;
            used[word] = pattern[i];
            
            bool result = dfs(pattern, i + 1, str, j + word.size(), mapping, used);
            if(result == true) return true;
            
            mapping.erase(pattern[i]);
            used.erase(word);
        }
        
        return false;
    }
};

/* Approach 1-2: DFS (Optimized)
Intuition:
Time complexity:O()
Space complexity: O()
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str)
    {
        
        unordered_map<char, string> mapping;
        unordered_set<string> used;
        
        return dfs(pattern, 0, str, 0, mapping, used);
    }
    
    bool dfs(string &pattern, int i,
             string &str, int j,
             unordered_map<char, string> &mapping, unordered_set<string> &used)
    {
        if(i == pattern.size() || j == str.size()) return i == pattern.size() && j == str.size();
        
        if(mapping.count(pattern[i]) == 1)
        {
            string word = mapping[pattern[i]];
            if(str.substr(j, word.size()) != word) return false;
            return dfs(pattern, i + 1, str, j + word.size(), mapping, used);
        }
        
        // if pattern[i] has no mapping string yet
        int remChars = pattern.size() - i - 1;
        string word = "";
        for(int index = j; index < str.size() - remChars; ++index)
        {
            word += str[index];
            
            if(used.count(word) == 1) continue;
            
            mapping[pattern[i]] = word;
            used.insert(word);
            
            bool result = dfs(pattern, i + 1, str, index + 1, mapping, used);
            if(result == true) return true;
            
            used.erase(word);
        }
        mapping.erase(pattern[i]);
        
        return false;
    }
};
