/* https://leetcode.com/problems/remove-duplicate-letters/ */

/* Approach 1: Greedy
Intuition: 貪心法 + 類似 stack 的概念。
           先計算所有字母出現次數存在 count 中，然後遍歷 s, 
           如果 1. ans 不為空
                2. count[ans.back() - 'a'] > 0
                3. ans.back() 比當前字母 c 大
           則代表可以把 and.back() 丟棄，而先使用當前的字母 c。
           Same as 1081. Smallest Subsequence of Distinct Characters.
           
Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        char count[26]{};
        for(auto c : s) ++count[c -'a'];
        
        string ans;
        bool visited[26]{};
        for(auto c : s)
        {
            --count[c - 'a'];
            
            if(visited[c -'a'] == true) continue;
            
            while(!ans.empty() and c < ans.back() and count[ans.back() - 'a'] > 0)
            {
                visited[ans.back() -'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(c);
            visited[c - 'a'] = true;     
        }
        
        return ans;
    }
};
