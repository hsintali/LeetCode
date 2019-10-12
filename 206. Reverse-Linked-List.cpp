/* https://leetcode.com/problems/reverse-linked-list/ */

/* Approach 1:
Intuition: 

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *prev = NULL;
        ListNode *cur = head;
        
        while(cur != NULL)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
    
        }

        return prev;
    }
};
