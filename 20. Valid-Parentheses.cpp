/* https://leetcode.com/problems/valid-parentheses/ */

/* Approach 1: stack
Intuition:

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
        
        stack<char> stack_;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mapping.count(s[i]) == 1) //encounter closing bracket
            {
                char c = stack_.empty()? '#' : stack_.top();
                if(c == mapping[s[i]])
                {
                    stack_.pop();
                }
                else
                {
                    return false;
                }
                    
            }
            else //encounter opening bracket
            {
                stack_.push(s[i]);
            }
        }
        
        return stack_.empty() ? true : false;
    }
};
