/* https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ */

/* Approach 1:
Intuition:

Time complexity:  O(n)
Space complexity: O(6) = O(1)
*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        int mapA[7]{};
        int mapB[7]{};
        for(auto a : A) ++mapA[a];
        for(auto b : B) ++mapB[b];
        
        int same = 0;
        for(int i = 1; i <= 6; ++i)
        {
            if(mapA[i] == A.size()) return 0;
            if(mapB[i] == B.size()) return 0;
            if(mapA[i] + mapB[i] >= A.size()) same = i;
        }
        if(same == 0) return -1;
        
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] != same and B[i] != same) return -1;
        }        
        
        return (int)A.size() - max(mapA[same], mapB[same]);
    }
};

/* Approach 2:
Intuition: Try all possibilities from 1 to 6.
           If we can make number i in a whole row, it should satisfy that countA[i] + countB[i] - same[i] = n

Time complexity:  O(n)
Space complexity: O(6) = O(1)
*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        int mapA[7]{};
        int mapB[7]{};
        int same[7]{};
        for(int i = 0; i < A.size(); ++i)
        {
            ++mapA[A[i]];
            ++mapB[B[i]];
            if(A[i] == B[i]) ++same[A[i]];
        }
        
        for(int i = 1; i <= 6; ++i)
        {
            if(mapA[i] + mapB[i] - same[i] == A.size())
            {
                return (int)A.size() - max(mapA[i], mapB[i]);
            }
        }

        return -1;
    }
};
