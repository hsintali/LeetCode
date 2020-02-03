/* https://leetcode.com/problems/find-all-anagrams-in-a-string/ */

/* Approach 1: Hash: Brute Force
Intuition: 在 s 中掃描與 p 相同大小的所有子字串(O(n))，再判斷這個子字串是否與 p 為 anagram (O(m))

Time complexity: O(n*m), n=s.size(), m=p.size()
Space complexity: O(1)
*/

/* Approach 2: Hash + Sliding Window
Intuition: 使用 det 儲存 p 中的各個字元，然後透過 Sliding Window 方式來掃描 s 的某個子字串，在 det 中扣除該子串出現的字元。
           Sliding Window 滑動時，更新 det 中各字元出現的次數及 absSum。

Time complexity: O(n), n=s.size(), m=p.size()
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if(s.size() == 0 || p.size() == 0) return ans;
        
        unordered_map<char, int> det;
        
        // store count for each char in p
        for(auto c : p)
        {
            if(det.find(c) == det.end())
            {
                det[c] = 1;
            }
            else
            {
                ++det[c];
            }
        }
        
        // minus count for the char in the substring
        for(int i = 0; i < p.size(); ++i)
        {
            if(det.find(s[i]) != det.end())
            {
                --det[s[i]];
            }
        }
        
        int absSum = 0;
        for(auto item : det)
        {
            absSum += abs(item.second);
        }
        
        if(absSum == 0)
        {
            ans.push_back(0);
        }
        
        int left = 0; // pointer to the removed index
        int right = left + p.size(); // pointer to the added index
        while(right < s.size())
        {
            if(det.find(s[left]) != det.end())
            {
                absSum = absSum - abs(det[s[left]]);
                ++det[s[left]];
                absSum = absSum + abs(det[s[left]]);
            }
            
            if(det.find(s[right]) != det.end())
            {
                absSum = absSum - abs(det[s[right]]);
                --det[s[right]];
                absSum = absSum + abs(det[s[right]]);
            }
            
            if(absSum == 0)
            {
                ans.push_back(left + 1);
            }
            
            ++left;
            ++right;
        }
        
        return ans;
    }
};
