#include <stdio.h>
#include <string.h>
#include "events.h"
#include <time.h>


//Define booleans: TRUE 1, FALSE 0
#define TRUE 1
#define FALSE 0


//pointer
char *months[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//method for leap year (february)
int IsLeapYear (int year){
    
    return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


//function for daycode, we decided to use the time library and this was what we found after researching 
int GetDayCode (int year) {
    struct tm t = {0};
    t.tm_year = year - 1900;
    t.tm_mon = 0;
    t.tm_mday = 1;

    mktime(&t);

    return t.tm_wday;

}

// function to print calendar 
void DisplayCalendar(int year) {
    int monthLength[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

// update for leap year (fenruary)
    if (IsLeapYear(year)){
        monthLength[2] = 29;
    }

//get starting day of the year
int dayCode = GetDayCode(year); 

    for (int month = 1; month <= 12; month++){
        printf("\n\n-------- %s %d --------\n", months[month], year); // /033[  <-- use this after \n for escape sequences
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for (int i = 0; i < dayCode; i++){
            printf("    ");
        }

    //print the days of the month 
        for (int day = 1; day <= monthLength[month]; day++){
            printf("%4d", day);

            if ((day + dayCode) % 7 == 0){
            printf("\n"); // new line for the next week 
            }
        }

        printf("\n");
        dayCode = (dayCode + monthLength[month]) % 7; // update daycode for the next month 
    }
}

//function to print a specific month 
void PrintMonth(int year, int month){
    int monthLength[]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (IsLeapYear(year)){
        monthLength[2] = 29;
    }

    int dayCode = GetDayCode(year);

    for(int i = 1; i < month; i++){
        dayCode = (dayCode + monthLength[i]) % 7;
    }

    printf("\n\n-------- %s %d --------\n", months[month], year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    for(int i = 0; i < dayCode; i++){
        printf("    ");
    }

    for (int day = 1; day <= monthLength[month]; day++){
        if(HasEvent(month, day, year)){
            printf("\033[1;32m%4d\033[0m", day);
        }
        else {
            printf("%4d", day);
        }

        if((day + dayCode) % 7 == 0){
            printf("\n");
        }
    }

    printf("\n");
}

//function to print the entire clendar
void PrintCalendar(){
    int year;

    printf("Enter the year to print full calendar: ");
    scanf("%d", &year);

    DisplayCalendar(year);
    
}
