/* https://leetcode.com/problems/inorder-successor-in-bst-ii/ */

/* Approach 1: BST
Intuition:

Time complexity: O(H)
Space complexity: O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node)
    {
        if(node == nullptr) return nullptr;
        
        Node *successor = nullptr;
        
        if(node->right != nullptr)
        {
            successor = node->right;
            
            while(successor->left != nullptr)
            {
                successor = successor->left;
            }
            
            return successor;
        }
        
        while(node->parent != nullptr)
        {
            if(node->parent->left == node)
            {            
                successor = node->parent;
                return successor;
            }
            else if(node->parent->right == node)
            {
                node = node->parent;
            }
        }
        
        return successor;
    }
};
