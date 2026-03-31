// URL:        https://leetcode.com/problems/number-of-days-between-two-dates/
// Difficulty: Easy
//
// Write a program to count the number of days between two dates.
//
// The two dates are given as strings, their format is YYYY-MM-DD as shown
// in the examples.
//
// Example 1:
//   Input:  date1 = "2019-06-29", date2 = "2019-06-30"
//   Output: 1
//
// Example 2:
//   Input:  date1 = "2020-01-15", date2 = "2019-12-31"
//   Output: 15
//
// Constraints:
//   - The given dates are valid dates between the years 1971 and 2100.

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    bool isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    int yearToDays(int year) {
        return isLeapYear(year) ? 366 : 365;
    }

    int monthToDays(int year, int month) {
        switch (month) {
            case 1: return 31;
            case 2: return isLeapYear(year) ? 29 : 28;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: return -1;
        }
    }

    int dateToDays(int year, int month, int day) {
        int total = 0;
        int baseYear = 1970;
        int baseMonth = 1;

        while (baseYear < year) {
            total += yearToDays(baseYear++);
        }

        while (baseMonth < month) {
            total += monthToDays(year, baseMonth++);
        }

        total += day - 1;

        return total;
    }

    int daysBetweenDates(string date1, string date2) {
        if (date1 == date2) return 0;

        int d1Y = std::stoi(date1.substr(0, 4));
        int d1M = std::stoi(date1.substr(5, 2));
        int d1D = std::stoi(date1.substr(8, 2));

        int d2Y = std::stoi(date2.substr(0, 4));
        int d2M = std::stoi(date2.substr(5, 2));
        int d2D = std::stoi(date2.substr(8, 2));

        int d1Days = dateToDays(d1Y, d1M, d1D);
        int d2Days = dateToDays(d2Y, d2M, d2D);

        return std::abs(d1Days - d2Days);
    }
};

int main() { return 0; }
