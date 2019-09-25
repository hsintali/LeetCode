/* https://leetcode.com/problems/generate-parentheses/ */

/* Approach 1: brute force
Intuition: We can generate all 2^{2n}n sequences of '(' and ')' characters. Then, we will check if each one is valid.

Time complexity: O(2^{2n}n)
Space complexity: O(2^{2n}n)
*/

class Solution {
public:
    vector<string> results;
    int seqSize;
    
    vector<string> generateParenthesis(int n)
    {
        seqSize = 2 * n;
        string seq;
        generate(seq, 0);
        return results;        
    }
    
    void generate(string seq, int pos)
    {
        if(pos == seqSize)
        {
            if(isValid(seq))
                results.push_back(seq);
        }
        else
        {
            generate(seq + '(', pos + 1);
            generate(seq + ')', pos + 1);
        }
    }
    
    bool isValid(string seq)
    {
        int count = 0;

        for(int i = 0; i < seq.size(); ++i)
        {
            if(seq[i] == '(')
                ++count;
            else
                --count;
            
            if(count < 0)
                return false;
        }

        return count == 0;
    }
};

/* Approach 2: backtracking
Intuition: We only add parentheses when we know it will remain a valid sequence.

Time complexity: 
Space complexity: 
*/

class Solution {
public:
    vector<string> results;
    
    vector<string> generateParenthesis(int n)
    {
        string seq;
        backtrack(seq, 0, 0, n);
        return results;        
    }
    
    void backtrack(string seq, int left, int right, int n)
    {
        if(seq.size() == 2 * n)
        {
            results.push_back(seq);
        }
        else
        {
            if(left < n)
                backtrack(seq + '(', left + 1, right, n);
            
            if(right < left)
                backtrack(seq + ')', left, right + 1, n);
        }
    }
};
