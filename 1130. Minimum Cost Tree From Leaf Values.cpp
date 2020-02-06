/* https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/ */

/* Approach 1: Stack
Intuition: 希望 cost 最小，我們會希望:
           1. 大的數字在上層，這樣這個大數字會被乘比較少次
           2. 小的數字在下層，這個小數字可以被乘比較多次
           所以，當
           1. arr 是遞增時，[1 2 3 4 5]:直接從左邊乘到右邊，從左邊到右邊建立子樹
           2. arr 是遞減時，[5 4 3 2 1]:要從右邊乘到左邊，從右邊到左邊建立子樹
           3. arr 先增後減時，[1 2 5 4 3]:可拆分成(1)+(2)的情況
           4. arr 先減後增時，[3 2 1 4 5]:可拆分成(1)+(2)的情況
           因此，實作時，現在 stack 放一個 INT_MAX，然後從左邊開始讀 arr
           1. 當 arr[i] > stack.top() 時，mid = stack.top() 然後 pop() 掉，
              再比較左邊的 stack.top() 和右邊的 arr[i]，中間要選擇和小的那一個數建立子樹(相乘)
           2. 當 arr[i] < stack.top() 時，因為是遞減，要從右邊乘到左邊，
              所以 stack.push(arr[i])
           3. arr[i] == stack.top()， (1) (2) 都可以。
           
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr)
    {
        stack<int> stk;
        int cost = 0;
        
        // to ensure stk.top() will return a value
        stk.push(INT_MAX);
        
        for(auto a : arr)
        {
            // multiplied from left to right
            while(a > stk.top())
            {
                int mid = stk.top();
                stk.pop();
                
                cost += mid * min(stk.top(), a);
            }
            
            stk.push(a);
        }
        
        // multiplied from right to left
        while(stk.size() > 2)
        {
            int right = stk.top();
            stk.pop();
            cost += stk.top() * right;
        }
        
        return cost;      
    }
};
