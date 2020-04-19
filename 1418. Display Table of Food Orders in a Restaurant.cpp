/* https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ */

/* Approach 1:
Intuition:

Time complexity:  O(N + TlogT + FlogF), N, T, F stands for amount of orders, tables and foods
Space complexity: O(T * F)
*/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders)
    {
        // {table: {food: amount}}
        map<int, unordered_map<string, int>> tables;
        set<string> foods;
        
        for(auto &order : orders)
        {
            foods.insert(order[2]);
            ++tables[stoi(order[1])][order[2]];
        }
        
        vector<string> header;
        header.push_back("Table");        
        for(auto &food : foods)
        {
            header.push_back(food);
        }
        
        vector<vector<string>> ans;
        ans.push_back(header);
        
        for(auto &table : tables)
        {
            vector<string> t;
            t.push_back(to_string(table.first));
            
            for(auto &food : foods)
            {
                if(table.second.count(food) == 1)
                {
                    t.push_back(to_string(table.second[food]));
                }
                else
                {
                    t.push_back("0");
                }
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};
