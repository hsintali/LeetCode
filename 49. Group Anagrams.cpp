/* https://leetcode.com/problems/group-anagrams/ */

/* Approach 1: Hash, Categorize by Sorted String
Intuition: 將 str 排序過後，作為 hashMap 的 key

Time complexity: O(N * KlogK), where N is the length of strs, and K is the maximum length of a string in strs. 
Space complexity: O(NK)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        if(strs.size() == 0) return ans;
        
        unordered_map<string, vector<string>> umap;
        
        for(auto &s : strs)
        {
            string stringKey = s;
            sort(stringKey.begin(), stringKey.end());       
            umap[stringKey].push_back(s);
        }
        
        for(auto &stringSet : umap)
        {
            ans.push_back(stringSet.second);
        }
        
        return ans;
    }
};

/* Approach 2: Hash, Categorize by Count
Intuition: 將 str 編碼成一個字串表示各字母出現的次數，作為 hashMap 的 key。實際上 Time & Space 比 方法1 還差。

Time complexity: O(NK), where N is the length of strs, and K is the maximum length of a string in strs. 
Space complexity: O(NK)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        if(strs.size() == 0) return ans;
        
        unordered_map<string, vector<string>> umap;
        
        for(auto &s : strs)
        {
            string stringKey = toKey(s);
            
            umap[stringKey].push_back(s);
        }
        
        for(auto &stringSet : umap)
        {
            ans.push_back(stringSet.second);
        }
        
        return ans;
    }
    
    string toKey(string s)
    {
        int arr[26] = {0};
        
        for(auto &c : s)
        {
            ++arr[c - 'a'];
        }
        
        string key;
        for(auto &a : arr)
        {
            key += "#";
            key += to_string(a);
        }
        
        return key;
    }
};
