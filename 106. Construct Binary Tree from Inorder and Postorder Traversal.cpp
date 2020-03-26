/* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */

/* Approach 1: DFS
Intuition: postorder 的最後一個元素是整棵(子)樹的"根"。再透過這個根去找 inorder 的根的位置 p。
           因此，inorder[:p] 為左子樹，inorder[p+1:] 為右子樹。
           再透過分治法處理左右兩邊子樹。
           
Time complexity: O(V) = O(n)
Space complexity: O(H)
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(postorder.size() != inorder.size()) return nullptr;
        
        return divideAndConquer(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    // return root of subtree
    TreeNode* divideAndConquer(vector<int>& inorder, int i_in, int j_in, vector<int>& postorder, int i_post, int j_post)
    {
        if(i_in > j_in || i_post > j_post) return nullptr;
        
        int rootVal = postorder[j_post];
        
        int index_in_root;
        for(int i = i_in; i <= j_in; ++i)
        {
            if(inorder[i] == rootVal) index_in_root = i;
        }
        int left_length = index_in_root - i_in;
        
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = divideAndConquer(inorder, i_in, index_in_root - 1, postorder, i_post, i_post + left_length - 1);
        root->right = divideAndConquer(inorder, index_in_root + 1, j_in, postorder, i_post + left_length, j_post - 1);
        
        return root;
    }
};
