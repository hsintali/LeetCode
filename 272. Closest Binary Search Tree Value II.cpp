/* https://leetcode.com/problems/closest-binary-search-tree-value-ii/ */

/* Approach 1: DFS
Intuition:

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
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        list<int> ans;
        
        inorder(root, target, k, ans);
        
        return vector<int>(ans.begin(), ans.end());
    }
    
    void inorder(TreeNode *root, double target, int k, list<int> &ans)
    {
        if(root == nullptr) return;
        
        inorder(root->left, target, k, ans);
        
        if(ans.size() == k && abs((double)root->val - target) < abs((double)ans.front() - target))
        {
            ans.pop_front();
            ans.push_back(root->val);
        }
        else if(ans.size() < k)
        {
            ans.push_back(root->val);
        }
        else
        {
            return;
        }
        
        inorder(root->right, target, k, ans);
    }
};

/* Approach 2: BST Iterator
Intuition:

Time complexity: O(H + k) = O(logn + k)
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
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        stack<TreeNode*> succStack;
        stack<TreeNode*> predStack;
        vector<int> ans;
        
        initStack(root, target, succStack, predStack);
        
        while(k-- > 0)
        {
            if(succStack.empty() || !predStack.empty() && (target - predStack.top()->val) < (succStack.top()->val - target))
            {
                ans.push_back(predStack.top()->val);
                getPredecessor(predStack);
            }
            else
            {
                ans.push_back(succStack.top()->val);
                getSuccessor(succStack);
            }
        }
            
        return ans;
    }
    
    void initStack(TreeNode *node, double target, stack<TreeNode*> &succStack, stack<TreeNode*> &predStack)
    {
        while(node != nullptr)
        {
            if(node->val <= target)
            {
                predStack.push(node);
                node = node->right;
            }
            else
            {
                succStack.push(node);
                node = node->left;
            }
        }
    }
    
    void getSuccessor(stack<TreeNode*> &succStack)
    {
        TreeNode *node = succStack.top();
        succStack.pop();
        
        if(node->right != nullptr)
        {
            node = node->right;
            while(node != nullptr)
            {
                succStack.push(node);
                node = node->left;
            }
        }
    }
    
    void getPredecessor(stack<TreeNode*> &predStack)
    {
        TreeNode *node = predStack.top();
        predStack.pop();
        
        if(node->left != nullptr)
        {
            node = node->left;
            while(node != nullptr)
            {
                predStack.push(node);
                node = node->right;
            }
        }
    } 
};
