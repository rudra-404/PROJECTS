#include <iostream>
#include<iomanip>
using namespace std;

int getFirstDayOfYear(int year) {
    int day = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return day;
}

int main() {
    const char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, totalDays, weekDay = 0, spaceCounter, year;
    
    cout << "CALENDAR Year : ";
    cin >> year;
    cout << "\n\n****************** YEAR " << year << " ******************";

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days[1] = 29;
    }
    
    weekDay = getFirstDayOfYear(year);
    
    for (i = 0; i < 12; i++) {
        cout << "\n\n\n------------------    " << months[i] << "    ------------------\n";
        cout << "\n    Sun   Mon   Tue   Wed   Thu   Fry   Sat\n";
        totalDays = days[i];
        
        for (spaceCounter = 1; spaceCounter <= weekDay; spaceCounter++) {
            cout << "      ";
        }
        
        for (j = 1; j <= totalDays; j++) {
            cout << setw(6) << j;
            weekDay++;
            
            if (weekDay > 6) {
                weekDay = 0;
                cout << "\n";
            }
        }
    }
    return 0;
}