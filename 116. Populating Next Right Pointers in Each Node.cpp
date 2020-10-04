/* https://leetcode.com/problems/populating-next-right-pointers-in-each-node/ */

/* Approach 1: BFS
Intuition:

Time complexity:  O(V + E) = O(n)
Space complexity: O(E) = O(log n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root == nullptr) return nullptr;
        
        queue<Node*> que;
        que.push(root);
        
        Node *pre = nullptr;
        
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; ++i)
            {
                Node *cur = que.front();
                que.pop();
                
                if(cur->left != nullptr) que.push(cur->left);
                if(cur->right != nullptr) que.push(cur->right);
                
                if(i > 0) pre->next = cur;
                
                pre = cur;
            }
        }
        
        return root;
    }
};