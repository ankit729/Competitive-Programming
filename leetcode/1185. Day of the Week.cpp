// Given a date, return the corresponding day of the week for that date.

// The input is given as three integers representing the day, month and year respectively.

// Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

// Example 1:

// Input: day = 31, month = 8, year = 2019
// Output: "Saturday"
// Example 2:

// Input: day = 18, month = 7, year = 1999
// Output: "Sunday"
// Example 3:

// Input: day = 15, month = 8, year = 1993
// Output: "Sunday"
 

// Constraints:

// The given dates are valid dates between the years 1971 and 2100.

class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        string mp[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        int sum=4;
        for(int i=1971;i<y;++i)
            sum+=365+isLeap(i);
        int MonthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
        MonthDays[1]+=isLeap(y);
        m--;
        for(int i=0;i<m;++i)
            sum+=MonthDays[i];
        sum+=d;
        return mp[sum%7];
    }
private:
    bool isLeap(int y) {
        return y%400==0 || (y%4==0 && y%100!=0);
    }
};
