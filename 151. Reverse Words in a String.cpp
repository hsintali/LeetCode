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

/* Approach 3: in place
Intuition: 先去頭去尾的空格，再去掉每個字之間多出的空格
           整個字串翻轉一次，再針對每個 word 翻轉回來。

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    string reverseWords(string s)
    {
        if(s.size() == 0) return "";
        
        int start = 0;
        int end = 0;
        
        // remove leading spaces
        int pos = 0;
        while(s[pos] == ' ' && pos < s.size())
        {
            ++pos;
        }
        start = pos;
        
        // remove trailing spaces
        pos = s.size() - 1;
        while(s[pos] == ' ' && pos >= 0)
        {
            --pos;
        }
        end = pos;
        
        // remove extra spaces between words
        int len = 0;
        for(int i = start; i <= end; ++i)
        {
            if(s[i] == ' ' && s[i - 1] == ' ')
            {
                continue;
            }
            
            s[len++] = s[i];
        }
        s.erase(s.begin() + len, s.end());
        
        // reverse s
        reverse(s.begin(), s.end());
        
        // reverse each reversed-word back to correct word
        int left = 0;
        int right = 0;
        while(left < s.size() && right < s.size())
        {
            while(s[right] != ' ' && right < s.size()) ++right;
   
            reverse(s.begin() + left, s.begin() + right);
            
            left = ++right;
        }
        
        return s;
    }
};
