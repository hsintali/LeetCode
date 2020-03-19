/* https://leetcode.com/problems/clone-graph/ */

/* Approach 1: BFS
Intuition: 使用 unordered_map 去 mapping 原本的 node 和 複製的 node。

Time complexity: O(V + E) = O(n)
Space complexity: O(V + E) = O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(node == nullptr) return nullptr;
        
        unordered_map<int, Node*> umap;
        
        queue<Node*> que;
        que.push(node);
        
        umap[node->val] = new Node(node->val);
        
        while(!que.empty())
        {
            Node *cur = que.front();
            que.pop();
            
            for(auto &neighbor : cur->neighbors)
            {
                if(umap.count(neighbor->val) == 0)
                {
                    umap[neighbor->val] = new Node(neighbor->val);
                    que.push(neighbor);
                }
                
                umap[cur->val]->neighbors.push_back(umap[neighbor->val]);
            }
        }
        
        return umap[node->val];
    }
};
