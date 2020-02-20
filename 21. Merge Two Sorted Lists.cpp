/* https://leetcode.com/problems/merge-two-sorted-lists/ */

/* Approach 1: Recursion
Intuition: mergeTwoLists 本身回傳已排序好的兩個 list 的 head，
           用遞迴方式，當 l1->val < l2->val，此時 l1 應該放在前面，所以 l1 的下一個要指向 mergeTwoLists(l1->next, l2) 的 head。

Time complexity: O(n + m)
Space complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

/* Approach 2: 迭代版
Intuition: 

Time complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(-1);
        
        ListNode *node = &dummy;
        
        while(l1 != NULL && l2 != NULL)
        {
            // append the smaller val to node
            if(l1->val < l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            
            // then proceed node to node->next
            node = node->next;
        }
        
        // append the remaining list
        node->next = (l1 == NULL) ? l2 : l1;
        
        // head->val is -1, so return head->next
        return dummy.next;
    }
};
