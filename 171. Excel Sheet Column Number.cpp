/* https://leetcode.com/problems/excel-sheet-column-number/ */

/* Approach 1:
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int titleToNumber(string s)
    {
        long long ans{};
        long long base = 1;
        
        for(int i = s.size() - 1; i >= 0; --i)
        {
            ans += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        
        return ans;
    }
};

/* Approach 2:
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int titleToNumber(string s)
    {
        long long ans{};
        
        for(int i = 0; i < s.size(); ++i)
        {
            ans = ans * 26 + (s[i] - 'A' + 1);
        }
        
        return ans;
    }
};
