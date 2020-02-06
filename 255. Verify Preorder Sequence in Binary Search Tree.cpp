/* https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/ */

/* Approach 1: stack
Intuition: 前序遍歷的特性是:
           1. 當遞減時，A[i+1] < A[i]，表示 A[i+1] 是 A[i] 的左節點
           2. 當遞增時，A[i+1] > A[i]，表示 A[i+1] 是 A[i] 的右節點
           3. 右子數的所有節點的數字都要小於該根節點
           因此，
           1. 將 根節點 以及 所有的左節點 都 push 到 stack 裡面作為其子節點的根節點
           2. 用 lowerBound(一開始是 INT_MIN) 儲存當前 被遍歷完成(只是經過不算遍歷完成，要到底再往回(pop)前一個根節點才算)的左節點 的下界，
              之後遇到的節點，都應該大於此值，否則 A 就是錯誤的順序，return false
           3. 若 A[i] < stk.top()，表示 A[i] 是 stk.top() 的左節點，因此 push 到 stack
           4. 若 A[i] > stk.top()，表示 A[i] 是一個右節點，
              更新 lowerBound = stack.top() 然後 pop() 掉這個數字，藉此來尋找 A[i] 的根節點
           5. 如果沒有與 (2) 矛盾，則代表 A 是前序遍歷

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder)
    {
        int lowerBound = INT_MIN;
        
        stack<int> stk;
        
        for(int i = 0; i < preorder.size(); ++i)
        {
            // every new val preorder[i] should greater than lowerBound
            if(preorder[i] < lowerBound) return false;
            
            // if preorder[i] < stk.top(), preorder[i] is right node
            while(!stk.empty() && preorder[i] > stk.top()) 
            {
                lowerBound = stk.top();
                stk.pop();
            }
            
            // if preorder[i] < stk.top(), preorder[i] is left node
            stk.push(preorder[i]); // push preorder[i] as an root
        }
        
        return true;
    }
};
