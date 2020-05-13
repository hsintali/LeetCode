/* https://leetcode.com/problems/remove-k-digits/ */

/* Approach 1: Monotonic Stack
Intuition: 要注意 coner case: 1. 去除 leading zeros 2. 若刪除後的 string 為 ""， 要改成 "0"

Time complexity:  O(n)
Space complexity: O(n + k)
*/

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        stack<int> stk; // store index
        
        num.push_back('0' - 1);
        
        for(int i = 0; i < num.size(); ++i)
        {      
            if(stk.empty() ||  num[stk.top()] - '0' < num[i] - '0')
            {
                stk.push(i);
            }
            else
            {
                while(k > 0 && (!stk.empty() &&  num[stk.top()] - '0' > num[i] - '0'))
                {
                    num[stk.top()] ='0' - 1;
                    stk.pop();
                    --k;
                }
                
                stk.push(i);
            }
            
            if(k == 0) break;
        }
        
        string ans;
        for(auto &c : num)
        {
            if(c != ('0' - 1)) ans.push_back(c);
        }
        
        int leadingZero = 0;
        for( ; leadingZero < ans.size(); ++leadingZero)
        {
            if(ans[leadingZero] != '0')
            {
                break;
            }
        }
        
        ans = ans.substr(leadingZero);
        if(ans == "") ans = "0";
        
        return ans;
    }
};
