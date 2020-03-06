/* https://leetcode.com/problems/day-of-the-week/ */

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<string> values = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        int daysToLastYear = 365 * (year - 1) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);
        
        int daysToLastMonth = 0;
        for(int i = 1; i < month; ++i)
        {
            daysToLastMonth += dayOfMonth[i];
        }
        if(month > 2 && year % 4 == 0) ++daysToLastMonth;
        
        int totalDays = daysToLastYear + daysToLastMonth + day;
        
        return values[totalDays % 7];     
    }
};
