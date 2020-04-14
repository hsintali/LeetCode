/* https://leetcode.com/problems/next-closest-time/ */

/* Approach 1:
Intuition:

Time complexity:O(1), O(4^4)
Space complexity: O(1)
*/

class Solution {
public:
    string nextClosestTime(string time)
    {
        string ans = time;
        
        unordered_set<string> nums, h1_nums, m1_nums;
        
        for(int i = 0; i <= 4; ++i)
        {
            int diff = time[i] - '0';
            
            if(diff >= 0 && diff <= 2) h1_nums.insert(time.substr(i, 1));
            if(diff >= 0 && diff <= 5) m1_nums.insert(time.substr(i, 1));
            if(diff >= 0 && diff <= 9) nums.insert(time.substr(i, 1));
        }
        
        int dist = INT_MAX;
        for(auto &h1 : h1_nums)
        {
            for(auto &h2 : nums)
            {
                if(h1[0] - '0' == 2 && h2[0] - '0' >= 4) continue;
                
                for(auto &m1 : m1_nums)
                {
                    for(auto &m2 : nums)
                    {
                        string t = h1 + h2 + ":" + m1 + m2;
                        
                        int new_dist = distance(time, t);
                        if(new_dist != 0 && new_dist < dist)
                        {
                            dist = new_dist;
                            ans = t;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    int distance(string time1, string time2)
    {
        int t1 = (time1 [4] - '0') + 10 * (time1 [3] - '0') + 60 * ((time1 [1] - '0') + 10 * (time1 [0] - '0'));
        int t2 = (time2 [4] - '0') + 10 * (time2 [3] - '0') + 60 * ((time2 [1] - '0') + 10 * (time2 [0] - '0'));
        
        return (1440 + t2 - t1) % 1440;
    }
};
