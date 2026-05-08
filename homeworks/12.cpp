#include <iostream>
#include <iomanip>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInYear(int year) {
    return isLeapYear(year) ? 366 : 365;
}

int daysInMonth(int year, int month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

int main() {
    long long x;
    cin >> x;
    
    int year = 1970;
    long long remaining = x;
    
    while (remaining >= daysInYear(year)) {
        remaining -= daysInYear(year);
        year++;
    }
    
    int month = 1;
    long long day_remaining = remaining;
    
    while (day_remaining >= daysInMonth(year, month)) {
        day_remaining -= daysInMonth(year, month);
        month++;
    }
    
    int day = day_remaining + 1;
    
    cout << year << "-"
         << setw(2) << setfill('0') << month << "-"
         << setw(2) << setfill('0') << day << endl;
    
    return 0;
}