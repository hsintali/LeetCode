/* https://leetcode.com/problems/longest-common-prefix/ */

/* Approach 1: Brute Force
Intuition: Vertical scanning

Time complexity: O(m*n). In the worst case there will be n equal strings with length m.
Space complexity: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = "";
        
        for(int i = 0; i < strs[0].size(); ++i)
        {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(strs[j][i] != c || strs[j].size() < i)
                    return prefix;
            }
            
            prefix.push_back(c);
        }
        
        return prefix;
    }
};

/* Approach 2: Divide and conquer
Intuition:

Time complexity: O(m*n). In the worst case there will be n equal strings with length m.
                 = T(n/2) + O(M)
Space complexity: O(mlogn)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.empty())
            return "";
        
        return LCP(strs, 0, strs.size() - 1);
    }
    
    string LCP(vector<string> &strs, int l, int r)
    {
        if(l == r)
        {
            return strs[r];
        }
        
        int mid = l + (r-l)/2;
        string leftString = LCP(strs, l, mid);
        string rightString = LCP(strs, mid + 1, r);

        return commonPrefix(leftString, rightString);
    }
    
    string commonPrefix(string &leftString, string &rightString)
    {
        int length = min(leftString.size(), rightString.size());
        for(int i = 0; i < length; ++i)
        {
            if(leftString[i] != rightString[i])
            {
                return rightString.substr(0, i);
            }
        }
        
        return rightString.substr(0, length);
    }
};







