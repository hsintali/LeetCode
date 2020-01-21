/* https://leetcode.com/problems/palindrome-linked-list/ */

/* Approach 1: Two pointer
Intuition: 將 linked-list 的值存到 vector，再用 two pointer 判斷。
Time complexity: O(n)
Space complexity: O(n)
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
    bool isPalindrome(ListNode* head)
    {
        vector<int> arr;
        
        ListNode *curr = head;
        
        // store the vals to arr
        while(curr != NULL)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        // two pointer to determine
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < right)
        {
            if(arr[left] != arr[right])
            {
                return false;
            }
            
            ++left;
            --right;
        }
        
        return true;
    }
};

/* Approach 2: Two pointer
Intuition: 找出 linked-list 中間點(後半段的 head)，分別出前半段及後半段，反轉其中一半段，分別遍歷判斷是否為 palindrome
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
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL) return true;
        
        ListNode* secondHead = findMiddle(head);
        secondHead = reverseLinkedList(secondHead);
        
        while(head != NULL && secondHead != NULL)
        {
            if(head->val != secondHead->val)
            {
                return false;
            }
            
            head = head->next;
            secondHead = secondHead->next;
        }
        
        return true;
    }
    
    // return the second head
    ListNode* findMiddle(ListNode* head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return (fast == NULL)? slow : slow->next;
    }
    
    // return the head of reversed Linked List
    ListNode* reverseLinkedList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while(curr != NULL)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
