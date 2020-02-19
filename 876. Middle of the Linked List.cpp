https://leetcode.com/problems/middle-of-the-linked-list/

/* Approach 1: Two Pointers
Intuition: 快慢指針

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
    ListNode* middleNode(ListNode* head)
    {
        ListNode * slow = head;
        ListNode * fast = head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return fast == NULL ? slow : slow->next;
    }
};
