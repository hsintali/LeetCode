/* https://leetcode.com/problems/reverse-nodes-in-k-group/ */

/* Approach 1:
Intuition: 注意: 
           k = 1 時，就是原本的連結，
           k = n 時，要重接 n - 1 次。

Assume k = 3:

a. Initial status
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
 pre    cur  next

b. cur->next = next->next 
dummy -> 1 ------> 3 -> 4 -> 5 -> 6 -> 7
              2 -> 3
 pre    cur  next

c. next->next = pre->next
dummy ------> 1 -> 3 -> 4 -> 5 -> 6 -> 7
         2 -> 1   
 pre   next  cur
 
d. pre->next = next
dummy -> 2 -> 1 -> 3 -> 4 -> 5 -> 6 -> 7            
 pre   next  cur

e. next = cur->next
dummy -> 2 -> 1 -> 3 -> 4 -> 5 -> 6 -> 7            
 pre         cur  next
           
Time complexity: O(n)
Space complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(head == NULL || k == 1) return head;
        
        int size = 0;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *pre, *cur, *next;
        pre = dummy;
        cur = head;
        
        while(cur != NULL)
        {
            cur = cur->next;
            ++size;
        }
        
        while(size >= k)
        {
            cur = pre->next;
            next = cur->next;
            
            for(int i = 1; i < k; ++i)
            {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            
            pre = cur;
            size -= k;
        }
        
        return dummy->next;
    }
};
