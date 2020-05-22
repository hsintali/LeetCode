/* https://leetcode.com/problems/sort-characters-by-frequency/ */

/* Approach 1: maxHeap + hashMap
Intuition:

Time complexity:  O(nlogn)
Space complexity: O(n)
*/

class Solution {
public:
    string frequencySort(string s)
    {
        int freq[256];
        for(int i = 0; i < 256; ++i)
        {
            freq[i] = 0;
        }
        
        for (auto &c : s)
        {
            ++freq[c];
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for(int i = 0; i < 256; ++i)
        {
            if(freq[i] == 0) continue;
            
            maxHeap.push(make_pair(freq[i], i));
        }
        
        string ans;
        while(!maxHeap.empty())
        {
            for(int i = 0; i < maxHeap.top().first; ++i)
            {
                ans += maxHeap.top().second;
            }
            
            maxHeap.pop();
        }
        
        return ans;
    }
};

/* Approach 2: bucket + hashMap
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    string frequencySort(string s)
    {
        int freq[256];
        for(int i = 0; i < 256; ++i)
        {
            freq[i] = 0;
        }
        
        for (auto &c : s)
        {
            ++freq[c];
        }
        
       vector<string> bucket(s.size() + 1, "");
        
        for(int i = 0; i < 256; ++i)
        {
            if(freq[i] == 0) continue;
            
            int n = freq[i];
            char c = (char)i;
                
            bucket[n].append(n , c);
        }
        
        string ans;
        for(int i = s.size(); i > 0; --i)
        {
            ans += bucket[i];
        }
        
        return ans;
    }
};
