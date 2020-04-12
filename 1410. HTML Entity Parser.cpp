/* https://leetcode.com/problems/html-entity-parser/ */

/* Approach 1: hashMap
Intuition:

Time complexity:O(n)
Space complexity: O(n)
*/

class Solution {
public:
    string entityParser(string text)
    {
        unordered_map<string, char> umap;
        umap["&quot;"] = '"';
        umap["&apos;"] = '\'';
        umap["&amp;"] = '&';
        umap["&gt;"] = '>';
        umap["&lt;"] = '<';
        umap["&frasl;"] = '/';
                    
        string ans;
        string temp = "";
        int start = -1, end = -1;
        
        for(int i = 0; i < text.size(); ++i)
        {
            if(text[i] == '&')
            {
                temp += text[i];
                
                start = i;
            }
            else if(text[i] == ';')
            {
                temp += text[i];
                
                end = i;
                string key = text.substr(start, end - start + 1);
                
                if(umap.count(key) == 1)
                {
                    ans += umap[key];
                }
                else
                {
                    ans += temp;
                }
                
                temp = "";
                start = -1;
                end = -1;
            }
            else if(start == -1)
            {
                ans += text[i];
            }
            else
            {
                temp += text[i];
            }
        }
        
        return ans + temp;
    }
};
