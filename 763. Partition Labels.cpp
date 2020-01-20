/* https://leetcode.com/problems/partition-labels/ */

/* Approach 1: Two pointer
Intuition: 先透過 hash map 存下 S 中各字母的最後一個位置，
           再透過 start, end 分別指向各個 part 的首尾位置，
           最後用 i 遍歷過整個 S。
           
Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> partitionLabels(string S)
    {
        unordered_map<int, int> hashMap;
        vector<int> ans;
        
        // find the last position of each letter
        for(int i = 0; i < S.size(); ++i)
        {
            hashMap[S[i] - 'a'] = i;
        }
        
        int start = 0; // pointer to the first index of a part
        int end = 0; // pointer to the last index of a part
        
        // i: pointer to current position of S
        for(int i = 0; i < S.size(); ++i)
        {
            end = max(end, hashMap[S[i] - 'a']);
            
            if(i == end)
            {
                ans.emplace_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};
