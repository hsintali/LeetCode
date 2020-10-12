/* https://leetcode.com/problems/buddy-strings/ */

/* Approach 1: Using Set
Intuition:

Time complexity:  O(n)
Space complexity: O(26) = O(1)
*/

class Solution {
public:
    bool buddyStrings(string A, string B)
    {
        if(A.size() != B.size() or A.size() < 2) return false;
        
        if(A == B and unordered_set<char>(A.begin(), A.end()).size() < A.size()) return true;
        
        vector<int> diff;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] != B[i])  diff.push_back(i);
            
            if(diff.size() > 2) return false;
        }
        
        return diff.size() == 2 and A[diff[0]] == B[diff[1]] and A[diff[1]] == B[diff[0]];
    }
};
