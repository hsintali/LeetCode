/* https://leetcode.com/problems/add-two-numbers/ */

/* Approach 1:
Intuition:

Time complexity:  O(max(m,n))
Space complexity: O(max(m,n))
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0;
        
        while(true)
        {
            int sum = carry;
            
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
                        
            cur->val = sum % 10;
            carry = sum / 10;
            
            if(l1 or l2 or carry)
            {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
            else
            {
                break;
            }
            
        }
        
        return dummy;
    }
};
