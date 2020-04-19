/* https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */

/* Approach 1: Greedy
Intuition: 想像有一群青蛙在繞圈: c->r->o->a->k。
           1. 當 ch = 'c' 時，代表有一隻青蛙要進入這個 circle，此時 ++croak['c']，
                                                            若終點 croak['k'] > 0 至少有一隻青蛙，則可視為是這隻青蛙重新進入起點，
                                                            若終點 croak['k'] == 0 沒有青蛙，則代表是新的青蛙進入起點。
           2. 當 ch = 'r', 'o', 'a', 'k' 時，代表青蛙要從上一個點跑到 ch 該點，則 ++croak[ch]，而前一個節點要 --croak[ch - 1]。
                                                                            此時若前一個節點沒有青蛙 croak[ch - 1] == 0，
                                                                            代表該點 ch 是不可能跑到的，因此回傳 -1。
           3. 若 'c', 'r', 'o', 'a' 之些點都還有青蛙，代表不符合條件，回傳 -1。
           4. 最後回傳終點 'k' 有幾隻青蛙。

Time complexity:O(n)
Space complexity: O(1)
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        if(croakOfFrogs.size() % 5 != 0) return -1;
        
        int croak[5] = {0};
        
        unordered_map<char, int> umap;
        umap.insert({'c', 0});
        umap.insert({'r', 1});
        umap.insert({'o', 2});
        umap.insert({'a', 3});
        umap.insert({'k', 4});
        
        for(auto &ch : croakOfFrogs)
        {
            int n = umap[ch];
            
            ++croak[n];
            
            if(n == 0)
            {
                if(croak[4] > 0) --croak[4];
            }
            else
            {
                if(croak[n - 1] <= 0) return -1;
                
                --croak[n - 1];
            }
        }
        
        if(croak[0] || croak[1] || croak[2] || croak[3]) return -1;
        
        return croak[4];
    }
};
