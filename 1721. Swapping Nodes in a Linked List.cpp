/* https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */

/* Approach 1: two pointers (one pass)
Intuition: When we reach k-th node, we set node1 to the current node, and node2 to the head. 
           We continue traversing the list, but now we also move node2.
           When we reach the end, node2 will points to k-th node from end.

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
    ListNode* swapNodes(ListNode* head, int k)
    {
        if(head == nullptr) return nullptr;
        
        ListNode *cur = head;
        ListNode *node1 = nullptr;
        ListNode *node2 = nullptr;
        
        while(cur != nullptr)
        {
            if(node2) node2 = node2->next;
            
            if(--k == 0)
            {
                node1 = cur;
                node2 = head;
            }
            
            cur = cur->next;
        }
        
        swap(node1->val, node2->val);
        
        return head;
    }
};
