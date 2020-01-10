/* https://leetcode.com/problems/linked-list-cycle-ii/ */

/* Approach 1: hashSet
Intuition: If we keep track of the nodes that we've seen already in a Set,
           we can traverse the list and return the first duplicate node.

Time complexity: O(n)
Space complexity: O(n)
*/

/* Approach 2: fast-slow two pointers (Floyd's Tortoise and Hare)
Intuition: 1.尋找循環長度:
             龜兔從起點同時出發，龜走一步、兔就走兩步。由於兔比龜快，當龜兔皆進入循環之中，兔必然領先數圈、從後方追上龜。
             當龜兔相遇，龜兔的行走距離差，即是循環長度的倍數。
             龜一倍速、兔兩倍速，龜兔的行走距離差，剛好是龜的行進距離。龜的行進距離即是循環長度的倍數。
           2.尋找循環起點：
             龜退回起點，兔原地待命，龜兔同時出發，龜走一步、兔走一步。龜兔相遇之處即是循環起點。

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
    ListNode *detectCycle(ListNode *head)
    {
        if(head == NULL) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        bool haveCycle = false;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                haveCycle = true;
                break;
            }
        }
        
        if(haveCycle == false) return NULL;
        
        ListNode *ptr1 = head;
        ListNode *ptr2 = fast;
        
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }
};
