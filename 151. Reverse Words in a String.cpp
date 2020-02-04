/* https://leetcode.com/problems/reverse-words-in-a-string/ */

/* Approach 1: stack
Intuition: 照順序讀取 word 再放到 stack 中。讀完之後再 pop 出來就會是反過來的 word。 

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    string reverseWords(string s)
    {
        string result;
        
        if(s.size() == 0) return result;
            
        stack<string> stk;
        
        int left = 0;
        int right = 0;
        while(left < s.size() && right < s.size())
        {
            left = right;
            while(s[left] == ' ' && left < s.size()) ++left;
            
            right = left;
            while(s[right] != ' ' && right < s.size()) ++right;
            
            if(left < right)
            {
                stk.push(s.substr(left, right - left));
            }
        }
        
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
            if(!stk.empty())
            {
                result += " ";
            }
        }
        
        return result;
    }
};

/* Approach 2: tricky
Intuition: 實際跑起來時間空間都比方法1 還差

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    string reverseWords(string s)
    {
        string result;
        
        if(s.size() == 0) return result;
        
        int left = 0;
        int right = 0;       
        while(left < s.size() && right < s.size())
        {
            left = right;
            while(s[left] == ' ' && left < s.size()) ++left;
            
            right = left;
            while(s[right] != ' ' && right < s.size()) ++right;
                                   
            if(left < right)
            {
                result = s.substr(left, right - left) + " " + result;
            }
        }
        
        // remove the last space
        return result.substr(0, result.size() - 1);
    }
};
