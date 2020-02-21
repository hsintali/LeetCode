/* https://leetcode.com/problems/sort-list/ */

/* Approach 1: Merge Sort (Recursion)
Intuition: 使用遞迴方式，將 list 拆成兩半，再合併(合併時會排序)。遞迴深度 logn。

Time complexity: O(nlog)
Space complexity: O(logn)
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
    ListNode* sortList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head;
                
        ListNode *secondHead = findMiddleAndBreak(head);
        
        return merge(sortList(head), sortList(secondHead));
    }
    
    // Time: O(n)
    ListNode* findMiddleAndBreak(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *middle = slow->next;
        slow->next = nullptr; // break list to two lists
        
        return middle;
    }
    
    // Time: O(n)
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(-1);
        ListNode *node = &dummy;
        
        while(l1 != nullptr && l2 != nullptr)
        {
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
            
            node = node->next;
        }
        
        node->next = (l1 == nullptr) ? l2 : l1;
        
        return dummy.next;
    }
};

/* Approach 2: Merge Sort (Iteration)
Intuition:

Time complexity: O(nlog)
Space complexity: O(1)
*/
