/* https://leetcode.com/problems/sort-list/ */

/* Approach 1: Merge Sort (Recursion: Top-Down)
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

/* Approach 2: Merge Sort (Iteration: Bottom-Up)
Intuition: while: 拆成多個 size 為 n 的 splits，然後兩兩 merge。
           for: 倍增 n 的大小。
           Ex: [4 | 2 | 3 | 1] => [2 4 | 1 3] => [1 2 3 4]
           
Time complexity: O(nlog)
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
    ListNode* sortList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head;
        
        int len = 0;
        ListNode *cur = head;
        
        // calculate the length of list
        while(cur != nullptr)
        {
            cur = cur->next;
            ++len;
        }
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *leftPart;
        ListNode *rightPart;
        ListNode *tail;
        ListNode *rest;
        
        for(int n = 1; n < len; n <<= 1)
        {
            // reset tail to dummy node
            tail = &dummy;
            
            // reset rest to the first node
            rest = tail->next;
            
            // To merge each two-splits with size n -> 2n
            // after merged, each split is sorted
            while(rest != nullptr)
            {
                leftPart = rest;
                
                // after this, leftPart is a list with size n
                rightPart = split(leftPart, n);
                
                // after this, rightPart is a list with size n, rest is the remaining list
                rest = split(rightPart, n);
                
                // merger two list with size n into a list with size 2n     
                pair<ListNode*, ListNode*> merged = merge(leftPart, rightPart);
                
                // link the preious part and the merged part
                tail->next = merged.first;
                
                // link the merged part and the rest part
                //merged.second->next = rest; // This part can skip
                
                // proceed tail
                tail = merged.second;
            }
        }
        
        return dummy.next;
    }
    
    // split the list into two list with size n  and N - n (the remaining)
    // return the head of second list with size N - n
    ListNode* split(ListNode *head, int n)
    {
        ListNode *node = head;
        
        while(node != nullptr && n > 1)
        {
            --n;
            node = node->next;
        }
        
        ListNode *secondHead = (node ? node->next : nullptr);
        
        if(node != nullptr)
        {
            node->next = nullptr;
        }
        
        return secondHead;
    }
    
    // Time: O(n)
    // return head and tail node of merged list
    pair<ListNode*, ListNode*> merge(ListNode *l1, ListNode *l2)
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
        
        while(node->next != nullptr) node = node->next;
        
        return {dummy.next, node};
    }
};
