/* https://leetcode.com/problems/linked-list-components/ */

/* Approach 1:
Intuition: Connected components in G must occur consecutively in the linked list.
           If cur->val in G and (cur->next not in list || cur->next->val not in G).
           Then this must be the end of a connected component.

Time complexity: O(N + G.length)
Space complexity: O(G.length)
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
    int numComponents(ListNode* head, vector<int>& G)
    {
        if(head == NULL) return 0;
        
        int ans = 0;
        unordered_set<int> set;
        
        for(auto i : G)
        {
            set.insert(i);
        }
        
        ListNode *cur = head;
        while(cur != NULL)
        {
            if(set.find(cur->val) != set.end() && // cur->val in G
               (cur->next == NULL || set.find(cur->next->val) == set.end())) //  cur->next not in list || cur->next->val not in G
            {
                ++ans;
            }
            
            cur = cur->next;
        }
        
        return ans;
    }
};
