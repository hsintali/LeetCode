/* https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/ */

/* Approach 1:
Intuition: Traverse the tree inoder, then link the pointers.
Time complexity: O(n)
Space complexity: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *first = NULL;
    Node *last = NULL;
    
    Node* treeToDoublyList(Node* root)
    {
        if(root == NULL) return NULL;
        
        inorderTraverse(root);
        last->right = first;
        first->left = last;
        
        return first;        
    }
    
    void inorderTraverse(Node *node)
    {
        if(node == NULL) return;
        
        // left child
        inorderTraverse(node->left);
        
        // node
        if(first == NULL)
        {
            first = node;
        }
        else
        {
            last->right = node;
            node->left = last;
        }
        
        last = node;
        
        // right child
        inorderTraverse(node->right);     
    }
};
