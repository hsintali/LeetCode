/* https://leetcode.com/problems/valid-word-abbreviation/ */

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        int sizeWord = word.size();
        int sizeAbbr = abbr.size();
        
        if(sizeWord == 0 || sizeAbbr == 0)
        {
            return false;
        }
        
        int indexWord = 0;
        int indexAbbr = 0;
        
        while(indexWord < sizeWord && indexAbbr < sizeAbbr)
        {
            if(isdigit(abbr[indexAbbr]))
            {
                if(abbr[indexAbbr] == '0')
                {
                    return false;
                }
                
                int val = 0;            
                while(indexAbbr < sizeAbbr && isdigit(abbr[indexAbbr]))
                {
                    int a = abbr[indexAbbr] - '0';
                    val = val * 10 + abbr[indexAbbr] - '0';
                    ++indexAbbr;
                }
                
                indexWord += val;
            }
            else
            {
                if(word[indexWord] != abbr[indexAbbr])
                {
                    return false;
                }
                
                ++indexWord;
                ++indexAbbr;
            }
        }
        
        return (indexWord == sizeWord && indexAbbr == sizeAbbr);
    }
};
