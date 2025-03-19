#include <stdio.h>
#include <string.h>

int main (void) {
    int year;

// update to something more simple along the way (pointers, abbreviations, etc)
int monthLength[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

char months[] = {" ", "Januaury", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

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

//method for year input


//method daycode

//


}
