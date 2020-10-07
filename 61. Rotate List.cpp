/* https://leetcode.com/problems/rotate-list/ */

/* Approach 1: 三步翻轉法
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr) return nullptr;
        
        // compute length
        int len = 1;
        ListNode *tail = head;
        while(tail->next != nullptr)
        {
            ++len;
            tail = tail->next;
        }
        
        // split into two lists
        int pivot = len - (k % len);
        ListNode *firstHead = head;
        ListNode *firstTail = head;
        for(int i = 1; i < pivot; ++i)
        {
            firstTail = firstTail->next;
        }
        ListNode *secondHead = firstTail->next;
        firstTail->next = nullptr;
        
        // reverse
        reverse(firstHead);       
        firstHead->next = reverse(secondHead);
        return reverse(firstTail);
    }
    
    // return the head of reversed list
    ListNode* reverse(ListNode *node)
    {
        if(node == nullptr) return nullptr;
        
        ListNode *cur = node;
        ListNode *prev = nullptr;
        
        while(cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};

/* Approach 2:
Intuition: 頭尾相連後，再找出 pivot 打斷連接。

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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr) return nullptr;
        
        // compute length, link head and tail
        int len = 1;
        ListNode *tail = head;
        while(tail->next != nullptr)
        {
            ++len;
            tail = tail->next;
        }
        tail->next = head;
        
        // breakup the pivot node
        int pivot = len - (k % len);
        for(int i = 1; i < pivot; ++i)
        {
            head = head->next;
        }
        ListNode *newHead = head->next;
        head->next = nullptr;
        
        return newHead;
    }
};
