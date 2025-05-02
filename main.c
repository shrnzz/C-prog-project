#include <stdio.h>
#include <string.h>
#include "calendar.h"  
#include "events.h"  

#define MAX_DESC 200
#define MAX_DATE 11

//compile using gcc main.c events.c calendar.c -o main and then ./a.out

int main (void) {
    int menuChoice = 0;
    char dateInput[MAX_DATE];

    
    // below is the code for a menu where users will have options to choose from 
    while(menuChoice != 3){
        LoadEventDates();
        printf("\n--- Calendar Menu ---\n");
        printf("Option 1: Enter Event\nOption 2: Look up Event\nOption 3: Exit & print full calendar\n");
        printf("Enter an option ");
        scanf("%d", &menuChoice);

        if(menuChoice == 1){
            int month, day, year;
            char description[MAX_DESC];

            printf("Enter a date in the following form: MM/DD/YYYY\n");
            scanf("%s", dateInput);

            sscanf(dateInput, "%d/%d/%d", &month, &day, &year); //sscanf will read from a strinf already in memory

            //validating month - anything over or under the normal date ranges will send an error
            if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1000){
                printf("Invalid date!\n");
                continue;
            } 

            //formats date
            char formattedDate[11];
            snprintf(formattedDate, sizeof(formattedDate), "%02d/%02d/%04d", month, day, year);
            
            printf("Enter events description: \n");
            getchar();
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0';

            AddingEvent(formattedDate, description);  //will store event 
            PrintMonth(year, month);              //will print calendar to show which day the event is stored 
        }
        else if(menuChoice == 2){
            int month, day, year;
            printf("Enter day to search event in this form: MM/DD/YYYY\n");
            scanf("%s", dateInput); 
            
            sscanf(dateInput, "%d/%d/%d", &month, &day, &year);

            if(month < 1 || month > 12 || day < 1 || day > 31 || year < 1000){
                printf("Invalid date!\n");
                continue;
            }

            char formattedDate[11];
            snprintf(formattedDate, sizeof(formattedDate), "%02d/%02d/%04d", month, day, year);

            SearchingEvent(formattedDate);      //will display event 
            PrintMonth(year, month);            //will print calendar to show which day the event is stored
        }
        else if(menuChoice != 3){
            printf("Invalid choice: please enter a valid choice\n");
        }
        
    }

    PrintCalendar(); //Ask user to enter year and print full calendar
    

    return 0;
}
