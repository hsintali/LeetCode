/* https://leetcode.com/problems/intersection-of-two-linked-lists/ */

/* Approach 1: Two Pointers
Intuition: 若有交集，diff = 長的 List 長度 - 短的 List 長度。
           長的 List 先從起點走 diff 步，然後 A，B 再同時走，第一個遇到的相同點，為交點。
           若走到 NULL 則沒交集。

Time complexity: O(m+n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int szA = 0;
        int szB = 0;
        
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        
        while(nodeA != NULL)
        {
            ++szA;
            nodeA = nodeA->next;
        }
        
        while(nodeB != NULL)
        {
            ++szB;
            nodeB = nodeB->next;
        }
        
        int diff = szA - szB;
        
        nodeA = headA;
        nodeB = headB;
        
        if(diff > 0)
        {
            for(int i = 0; i < abs(diff); ++i)
            {
                nodeA = nodeA->next;
            }
        }
        else
        {
            for(int i = 0; i < abs(diff); ++i)
            {
                nodeB = nodeB->next;
            }            
        }

        while(nodeA != NULL && nodeB != NULL && nodeA != nodeB)
        {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        return nodeA;
    }
};

/* Approach 2: Two Pointers
Intuition: A，B 都從頭開始走，
           當 A 走到終點 NULL 時，從 B 的起點開始走，
           當 B 走到終點 NULL 時，從 A 的起點開始走，
           第一個相遇的點，就是交點，
           如果後來又走到 NULL，則沒交集。

Time complexity: O(m+n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        
        while(nodeA != nodeB) 
        {
            nodeA = nodeA ? nodeA->next : headB;
            nodeB = nodeB ? nodeB->next : headA;
        }
        
        return nodeA;
    }
};
