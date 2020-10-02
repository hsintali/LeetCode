/* https://leetcode.com/problems/basic-calculator-ii/ */

/* Approach 1: stack
Intuition:

Time complexity:  O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int calculate(string s)
    {
        s = "+" + s + "+";
        int ans{};
        int val{};
        char op{'+'};
        stack<int> stk;
        
        for(auto c : s)
        {
            if(isspace(c)) continue;
            
            if(isdigit(c))
            {
                val = (10 * val) + (c - '0');
                continue;
            }
            
            if(op == '+')
            {
                stk.push(val);
            }
            else if(op == '-')
            {
                stk.push(-val);
            }
            else
            {
                int n{};
                if(op == '*')
                {
                    n = stk.top() * val;
                    
                }
                else if(op == '/')
                {
                    n = stk.top() / val;
                }
                
                stk.pop();
                stk.push(n);
            }
            
            val = 0;
            op = c;  
        }
        
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};
