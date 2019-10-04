/* https://leetcode.com/problems/zigzag-conversion/ */

/* Approach 1: Sort by Row
Intuition:
By iterating through the string from left to right, we can easily determine which row in the Zig-Zag pattern that a character belongs to.

Time Complexity: O(n), where n==len(s)

Space Complexity: O(n) 
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> lines(numRows);
        int line = 0;
        bool inc = false;
        
        for(int i = 0; i < s.size(); ++i)
        {
            lines[line] += s[i];        
            if (line == 0 || line == numRows - 1) inc = !inc;
            line += inc ? 1 : -1;
        }
        
        string out;
        for(string line : lines) out += line;
        return out;      
    }
};
