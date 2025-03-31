#include <stdio.h>
#include <string.h>

//Define booleans: TRUE 1, FALSE 0
#define TRUE 1
#define FALSE 0


//pointer
char *months[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//method for leap year (february)
int isLeapYear (int year){
    return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


//function for daycode, must use zellers formula to calculate first day of the year 
int getDayCode (int year) {
    int dayCode;
    int century = year / 100;
    int yearPart = year % 100;

    dayCode = (yearPart + (yearPart / 4) + (century / 4) - (2 * century) + 1 + 5) % 7;

    if (dayCode < 0){
        dayCode += 7;
    }
    
    return dayCode;
}

// function to print calendar 
void printCalendar(int year) {
    int monthLength[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

// update for leap year (fenruary)
    if (isLeapYear(year)){
        monthLength[2] = 29;
    }

//get starting day of the year
int dayCode = getDayCode(year); 

for (int month = 1; month <= 12; month++){
    printf("\n\n ------------ %s %d ------------\n", months[month], year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < dayCode; i++){
        printf("  ");
    }

//print the days of the month 
    for (int day = 1; day <= monthLength[month]; day++){
        printf("%5d", day);

        if ((day + dayCode) % 7 == 0){
         printf("\n"); // new line for the next week 
        }
    }

    printf("\n");
    dayCode = (dayCode + monthLength[month]) % 7; // update daycode for the next month 
}



//main function 
int main (){
    int year;

    printf("Enter year: ");
    scanf("%d", &year);

    printCalendar(year);

    return 0;
}

// professor said sturctures might be better than methods 