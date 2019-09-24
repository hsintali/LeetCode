/* https://leetcode.com/problems/count-and-say/ */

class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        if(n == 1) return seq;
        
        for(int i = 2; i <= n; ++i)
        {
            string res;
            char c = seq[0];
            int count = 0;
            
            for(int j = 0; j < seq.size(); ++j)
            {             
                if(seq[j] == c)
                {
                    ++count;
                }
                else
                {
                    res += std::to_string(count) + c;
                    count = 1;
                    c = seq[j];
                }
                
                if(j == seq.size() - 1)
                {
                    res += std::to_string(count) + c;
                }
            }
            
            seq = res;
        }
        
        return seq;
    }
};
