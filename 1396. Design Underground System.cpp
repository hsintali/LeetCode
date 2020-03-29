/* https://leetcode.com/problems/design-underground-system/ */

/* Approach 1: hashMap
Intuition: Assume each customer only appear one time.

Time complexity: checkIn: O(1), checkOut: O(1), getAverageTime: O(n)
Space complexity: O(n)
*/

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t)
    {
        inTime[stationName][id] = t;
    }
    
    void checkOut(int id, string stationName, int t)
    {
        outTime[stationName][id] = t;
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        unordered_map<int, int> in = inTime[startStation];
        unordered_map<int, int> out = outTime[endStation];
        
        int len = 0;
        int sum = 0;
        
        for(auto &out_it : out)
        {
            if(in.count(out_it.first) == 1)
            {
                sum += out_it.second - in[out_it.first];
                ++len;
            }
        }
        
        return (double)sum / (double)len;
    }
    
    unordered_map<string, unordered_map<int, int>> inTime;
    unordered_map<string, unordered_map<int, int>> outTime;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
 
 /* Approach 2: hashMap
Intuition:

Time complexity: checkIn: O(1), checkOut: O(1), getAverageTime: O(1)
Space complexity: O(n)
*/

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t)
    {
        inMap[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t)
    {
        auto &in = inMap[id];
        string path = in.first + "_" + stationName;
        outMap[path].first += t - in.second;
        outMap[path].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        string path = startStation + "_" + endStation;
        auto &out = outMap[path];
        return (double)out.first / (double)out.second;
    }
    
    unordered_map<int, pair<string, int>> inMap; // id: {stationName, inTime}
    unordered_map<string, pair<int, int>> outMap; // stationName: {totalTIme, count}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
