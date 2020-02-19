/* https://leetcode.com/problems/happy-number/ */

/* Approach 1: HashSet
Intuition:

Time complexity: O(logn)
Space complexity: O(logn)
*/

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> uset;
        
        while(n != 1)
        {
            if(uset.count(n) == 0)
            {
                uset.insert(n);
                n = getNext(n);
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
    
    int getNext(int n)
    {
        int sum = 0;
        
        while(n > 0)
        {
            int d = n % 10;
            n /= 10;
            sum += d * d;
        }
        
        return sum;
    }
};

/* Approach 2: Floyd's Cycle Detection
Intuition: 這題所產生的每個數值都是一個節點，若是 happy number 則代表沒有 cycle。
           若有 cycle，則無法變成 1，就不是 happy number。

Time complexity: O(logn)
Space complexity: O(1)
*/

class Solution {
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = getNext(n);
        
        while(fast != 1)
        {
            if(slow == fast)
            {
                return false;
            }
            
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return true;
    }
    
    int getNext(int n)
    {
        int sum = 0;
        
        while(n > 0)
        {
            int d = n % 10;
            n /= 10;
            sum += d * d;
        }
        
        return sum;
    }
};
