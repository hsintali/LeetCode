/* https://leetcode.com/problems/copy-list-with-random-pointer/ */

/* Approach 1: hashMap 遞迴版
Intuition: 使用 hashMap 紀錄 oldNode 對應到 copyNode。再透過遞迴方式 copy node->next, node->random。

Time complexity: O(n)
Space complexity: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL) return NULL;
        
        if(mapping.count(head) == 1)
        {
            return mapping[head];
        }
        
        Node *node = new Node(head->val);
        mapping[head] = node;
        
        node->random = copyRandomList(head->random);
        node->next = copyRandomList(head->next);
        
        return node;
    }
    
    unordered_map<Node*, Node*> mapping;
};

/* Approach 2: hashMap 非遞迴版
Intuition: 使用 hashMap 紀錄 oldNode 對應到 copyNode。再依序遍歷 Linked-List: copy node->next, node->random。

Time complexity: O(n)
Space complexity: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL) return NULL;
        
        Node *oldNode = head;
        Node *newNode = new Node(oldNode->val);
        mapping[oldNode] = newNode;
        
        while(oldNode != NULL)
        {
            newNode->next = getCopyNode(oldNode->next);
            newNode->random = getCopyNode(oldNode->random);
            
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        
        return mapping[head];
    }
    
    Node* getCopyNode(Node* oldNode)
    {
        if(oldNode == NULL) return NULL;
        
        if(mapping.count(oldNode) == 0)
        {
            Node *newNode = new Node(oldNode->val);
            mapping[oldNode] = newNode;
        }
        
        return mapping[oldNode];
    }
    
    unordered_map<Node*, Node*> mapping;
};
