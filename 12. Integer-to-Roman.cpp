/* https://leetcode.com/problems/integer-to-roman/ */

/*
Intuition:
給定一個數值 [int num]
首先減去 numbers 裡最大的數值，如果 num - numbers[index] >= 0，則代表需要輸出 numbers[index] 的羅馬字母；
如果 num - numbers[index] < 0，則代表需要減去 numbers[++index] 直到 num - numbers[++index] >= 0，然後再輸出其對應的羅馬字母。
*/

class Solution {
public:
    string intToRoman(int num)
    {
        string s = "";
        int numbers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int index = 0;
        
        while(num > 0)
        {
            int n = num - numbers[index];
            if(n < 0)
            {
                ++index;
                continue;
            }
            
            num -= numbers[index];
            
            switch(numbers[index])
            {
                case 1:
                    s += "I";
                    break;
                case 5:
                    s += "V";
                    break;
                case 10:
                    s += "X";
                    break;
                case 50:
                    s += "L";
                    break;
                case 100:
                    s += "C";
                    break;
                case 500:
                    s += "D";
                    break;
                case 1000:
                    s += "M";
                    break;
                case 4:
                    s += "IV";
                    break;
                case 9:
                    s += "IX";
                    break;
                case 40:
                    s += "XL";
                    break;
                case 90:
                    s += "XC";
                    break;
                case 400:
                    s += "CD";
                    break;
                case 900:
                    s += "CM";
                    break;
            }
        }
          
        return s;
    }
};
