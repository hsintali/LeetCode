/* https://leetcode.com/problems/merge-k-sorted-lists/ */

/* Approach 1: minHeap
Intuition: 要注意 lists 裡面可能會有 null: [[], [1, 2], []]

Time complexity: O(nlogk), n is total number of nodes
Space complexity: O(k)
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        for(auto node : lists)
        {
            if(node != nullptr) minHeap.push(node);
        }
        
        if(minHeap.empty()) return nullptr;
        
        ListNode *head = minHeap.top();
        minHeap.pop();    
        
        if(head->next != nullptr) minHeap.push(head->next);
        
        ListNode *node = head;
        
        while(!minHeap.empty())
        {
            node->next = minHeap.top();
            minHeap.pop();
            
            node = node->next;
            if(node->next != nullptr) minHeap.push(node->next);
        }
        
        return head;
    }
    
    struct compare
    {
        bool operator()(const ListNode *node1, const ListNode *node2)
        {
            return node1->val > node2->val;
        }
    };
};
