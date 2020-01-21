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
Intuition: 找出 linked-list 中間點，分別出前半段及後半段，反轉其中一半段，分別遍歷判斷是否為 palindrome
Time complexity: O(n)
Space complexity: O(1)
*/

