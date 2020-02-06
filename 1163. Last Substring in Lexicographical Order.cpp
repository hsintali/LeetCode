/* https://leetcode.com/problems/last-substring-in-lexicographical-order/ */

/* Approach 1:
Intuition: 存下最大字母子串的起始點 maxStringIdx，
           遍歷 s 的各個字母，如果遇到更大的字母，更新 maxStringIdx。
           如果當前遇到的字母和當前最大的字母相等，則
           1. 存下當前位置 cur_idx = i
           2. 設定 j 為最大自母子串的起始點，j = maxStringIdx
           3. 開始逐一比較，直到 s[i] != s[j]
           4. 如果 s[i] > s[j]，則更新 maxStringIdx = cur_idx
           5. 然後 continue，i 可以不用拉回去原本的位置，因為 maxStringIdx 已經被更新到 cur_idx
              而 [cur_idx, i-1] 這段子字串 與 未更新前的最大子字串是一樣的
              所以從 新的 i 開始繼續就可以

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    string lastSubstring(string s)
    {        
        int n = s.size();
        
        int maxStringIdx = 0;
        
        int i = 1;
        while(i < n)
        {
            if(s[i] > s[maxStringIdx])
            {
                maxStringIdx = i;
            }
            else if(s[i] == s[maxStringIdx])
            {
                int cur_idx = i;
                int j = maxStringIdx;
                
                while(i < n && j < cur_idx && s[i] == s[j])
                {
                    ++i;
                    ++j;
                }
                
                if(i < n && j < cur_idx && s[i] > s[j])
                {
                    maxStringIdx = cur_idx;
                }
                
                continue;
            }
            
            ++i;
        }
        
        return s.substr(maxStringIdx);
    }
};
