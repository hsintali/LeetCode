/* https://leetcode.com/problems/design-linked-list/ */

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct Node
    {
        int val;
        Node* next;
        
        Node(int v) : val(v), next(NULL) {}
    };
    
    Node *head;
    int size;
        
    MyLinkedList() : size(0) {
        head = new Node(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        
        int cnt = 0;
        Node *cur = head;
        
        while(cnt < index + 1)
        {
            ++cnt;
            cur = cur->next;
        }
        
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val);
        cur->next = head->next;
        head->next = cur;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *last = head;
        
        while(last->next != NULL)
            last = last->next;
        
        last->next = new Node(val);
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;
        
        ++size;
        int cnt = 0;
        
        Node *prev = head;

        while(cnt < index)
        {
            ++cnt;            
            prev = prev->next;
        }
        
        Node *cur = new Node(val);
        cur->next = prev->next;
        prev->next = cur;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        
        --size;
        int cnt = 0;
        Node *prev = head;

        while(cnt < index)
        {
            ++cnt;          
            prev = prev->next;
        }
        
        Node *cur = prev->next;
        prev->next = cur->next;
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
