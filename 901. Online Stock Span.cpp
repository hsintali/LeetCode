/* https://leetcode.com/problems/online-stock-span/ */

/* Approach 1: Monotonic Stack
Intuition: 
Time complexity:  O(n), where n is the number of calls. Amortized: O(1)
Space complexity: O(n)
*/

class StockSpanner {
public:
    StockSpanner()
    {
        
    }
    
    int next(int price)
    {
        int ans = 1;
        
        if(stk.empty() || stk.top().first > price)
        {
            stk.push(make_pair(price, 1));
        }
        else
        {
            while(!stk.empty() && stk.top().first <= price)
            {
                int count = stk.top().second;
                stk.pop();
                ans += count;
            }
            
            stk.push(make_pair(price, ans));
        }
        
        return ans;
    }
    
    stack<pair<int,int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
