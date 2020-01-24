/* https://leetcode.com/problems/binary-search-tree-iterator/ */

/* Approach 1: inorder traverse + queue
Intuition: 中序遍歷 tree 並將結果存到 queue。Space 不符合題目要求(須為 O(logn) )。

Time complexity: constructor():O(n)
                 next():O(1)
                 hasNext():O(1)
Space complexity: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root)
    {
        inorderTraverse(root);
    }
    
    /** @return the next smallest number */
    int next()
    {
        int val = queue_.front()->val;
        
        if(!queue_.empty())
        {
            queue_.pop();
        }
        
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !queue_.empty();
    }
    
    queue<TreeNode*> queue_;
    
    void inorderTraverse(TreeNode *node)
    {
        if(node == NULL) return;
        
        inorderTraverse(node->left);
        queue_.push(node);
        inorderTraverse(node->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 /* Approach 2:
Intuition: 

Time complexity: O(1)
Space complexity: O(n)
*/
