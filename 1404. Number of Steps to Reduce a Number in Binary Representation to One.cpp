/* https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/ */

/* Approach 1: Simulation, brute force
Intuition:

Time complexity: O(n^2)
Space complexity: O(1)
*/

class Solution {
public:
    int numSteps(string s)
    {
        int count = 0;
        
        while(s.size() > 1)
        {
            if(s[s.size() - 1] - '0' == 0) 
            {
                ++count;
                divide(s);
            }
            else if(s[s.size() - 1] - '0' == 1)
            {
                ++count;
                count += addOne(s);
            }
        }
        
        return count;
    }
    
    void divide(string &s)
    {
        s.pop_back();
    }
    
    int addOne(string &s)
    {
        int carry = 0;
        
        int index = s.size() - 1;
        while(index >= 0)
        {
            if(s[index] - '0' == 1)
            {
                s[index] = '0';
                carry = 1;
            }
            else if(s[index] - '0' == 0)
            {
                s[index] = '1';
                carry = 0;
                break;
            }
            
            --index;
        }
        
        return carry;
    }
};

/* Approach 2: Simulation
Intuition:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int numSteps(string s)
    {
        int count = 0;
        int carry = 0;
        
        for(int i = s.size() - 1; i > 0; --i)
        {
            if(s[i] - '0' + carry == 1)
            {
                carry = 1;
                count += 2;
            }
            else// s[i] - '0' + carry is 00 or 10
            {
                ++count;
            }
        }
        
        return count + carry;
    }
};
