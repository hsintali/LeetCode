/* https://leetcode.com/problems/odd-even-linked-list/ */

/* Approach 1:
Intuition:

Time complexity:  O(n)
Space complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode *oddNode = new ListNode(-1);
        ListNode *evenNode = new ListNode(-1);
        ListNode *evenHead = evenNode;
        ListNode *curNode = head;
        bool isEven = false;
        
        while(curNode != nullptr)
        {
            if(isEven)
            {
                evenNode->next = curNode;
                evenNode = evenNode->next;
                curNode = curNode->next;
                evenNode->next = nullptr;
            }
            else
            {
                oddNode->next = curNode;
                oddNode = oddNode->next;
                curNode = curNode->next;
                oddNode->next = nullptr;
            }
            
            isEven = !isEven;
        }
        
        oddNode->next = evenHead->next;
        
        return head;
    }
};
