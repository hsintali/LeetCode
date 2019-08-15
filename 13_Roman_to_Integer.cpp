/*
https://leetcode.com/problems/roman-to-integer/

*/
class Solution {
public:
    int romanToInt(string s) {
        int *number = new int[s.size()];
        int n = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case 'I':
                    number[i] = 1;
                    break;
                case 'V':
                    number[i] = 5;
                    break;
                case 'X':
                    number[i] = 10;
                    break;
                case 'L':
                    number[i] = 50;
                    break;
                case 'C':
                    number[i] = 100;
                    break;
                case 'D':
                    number[i] = 500;
                    break;
                case 'M':
                    number[i] = 1000;
                    break;
            }
            n += number[i];
            
            if(i == 0)
                continue;
            
            // If the current number is larger than previous number, it means a substraction
            // Ex: IV (current number[i] is 'V')
            if(number[i] > number[i-1])
                n -= 2*number[i-1];
        }
        
        delete []number;
        
        return n;
    }
};
