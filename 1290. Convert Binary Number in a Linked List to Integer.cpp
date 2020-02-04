/* https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/ */

/* Approach 1:

Intuition:
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
    int getDecimalValue(ListNode* head)
    {
        if(head == NULL) return 0;
        
        int number = 0;
        
        while(head != NULL)
        {
            number = number * 2 + head->val;
            head = head->next;
        }
        
        return number;
    }
};
