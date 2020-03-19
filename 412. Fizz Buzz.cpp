/* https://leetcode.com/problems/fizz-buzz/ */

class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        
        for(int num = 1; num <= n; ++num)
        {
            bool isDivisibleBy3 = (num % 3 == 0);
            bool isDivisibleBy5 = (num % 5 == 0);
            
            string text = "";
            
            if(isDivisibleBy3) text += "Fizz";
            if(isDivisibleBy5) text += "Buzz";
            
            if(text == "") text += to_string(num);
            
            ans.push_back(text);
        }
        
        return ans;
    }
};
