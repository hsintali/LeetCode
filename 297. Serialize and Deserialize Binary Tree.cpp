/* https://leetcode.com/problems/serialize-and-deserialize-binary-tree/ */

/* Approach 1: BFS
Intuition:

Time complexity: O(V + E) = O(n)
Space complexity: O(V + E) = O(n)
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(root == nullptr) return "";
        
        string result;
        result += to_string(root->val);
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            
            if(node->left)
            {
                que.push(node->left);
                result += "," + to_string(node->left->val);
            }
            else
            {
                result += ",#";
            }
            
            if(node->right)
            {
                que.push(node->right);
                result += "," + to_string(node->right->val);
            }
            else
            {
                result += ",#";
            }
        }
        
        while(result.back() == '#' || result.back() == ',') result.erase(result.end() - 1);
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if(data.size() == 0) return nullptr;
        
        string::iterator end = find(data.begin(), data.end(), ',');
        string val(data.begin(), end);
        
        TreeNode *head = new TreeNode(stoi(val));
        
        if(end == data.end()) return head;
        
        queue<TreeNode*> que;
        que.push(head);
        
        string::iterator start = ++end;
        
        while(start != data.end())
        {
            if(*start == ',') continue;
            
            TreeNode *node = que.front();
            que.pop();
            
            if(*start != '#')
            {
                end = find(start, data.end(), ',');
                int val = stoi(string(start, end));
                TreeNode *left = new TreeNode(val);
                node->left = left;
                que.push(left);
                start = end + 1;
            }
            else
            {
                start += 2;
            }
            
            if(end == data.end()) break;
            
            if(*start != '#')
            {
                end = find(start, data.end(), ',');
                int val = stoi(string(start, end));
                TreeNode *right = new TreeNode(val);
                node->right = right;
                que.push(right);
                start = end + 1;
            }
            else
            {
                start += 2;
            }
            
            if(end == data.end()) break;
        }
        
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
