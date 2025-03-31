#include <stdio.h>
#include <string.h>

//Define booleans: TRUE 1, FALSE 0
#define TRUE 1
#define FALSE 0

// update to something more simple along the way (pointers, abbreviations, etc)
int monthLength[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

//pointer
char *months[] = {" ", "Januaury", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//method for leap year (february)
int isLeapYear (int year);
{
    if (year % 4== FALSE && year%100 != FALSE || year%400 == FALSE) {
        monthLength[2] = 29;
        return TRUE;
    }
    else {
        monthLength[2] = 28;
        return FALSE;
    }
}

// functions for year input

//method daycode

//method for leap year 

//function for calender (void calender)

// main function calls on void; add user input 

// professor said sturctures might be better than methods 