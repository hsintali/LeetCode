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
        char op{};
        stack<int> stk;
        
        for(auto c : s)
        {
            if(isspace(c)) continue;
            
            if(isdigit(c))
            {
                val = (10 * val) + (c - '0');
                continue;
            }
            
            if(op == '+' or op == '-')
            {
                val = (op == '+' ? val : -val);
                stk.push(val);
            }
            else if(op == '*' or op == '/')
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

/* Approach 2:
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int calculate(string s)
    {
        s = "+" + s + "++";
        int ans{};
        int val{};
        int prev{};
        char op{};
        
        for(auto c : s)
        {
            if(isspace(c)) continue;
            
            if(isdigit(c))
            {
                val = (10 * val) + (c - '0');
                continue;
            }
            
            // [prev] [op] [val] [cur_char c is an operator]
            if(op == '+' or op == '-')
            {
                ans += prev;
                prev = (op == '+' ? val : -val);
            }
            else
            {
                if(op == '*')
                {
                    prev *= val;
                    
                }
                else if(op == '/')
                {
                    prev /= val;
                }
            }
            
            val = 0;
            op = c;  
        }
        
        return ans;
    }
};
