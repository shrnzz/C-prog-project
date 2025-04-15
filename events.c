#include <stdio.h>
#include <string.h>

/*
events from user input will be saved into the events.txt file in the 
following format:

MM/DD/YY | Brunch with friends at 1pm.

*/

//Below is the code to add an event

void AddingEvent(const char* date, const char* description) {
    FILE *file = fopen ("events.txt", "a");  //this is for append mode

    if(file == NULL){
        printf("File-Error!\n Unable to open events file.\n");
        return;
    }

    fprintf(file, "%s | %s\n", date, description);
    fclose(file);
    printf("Event is saved!\n");
}

// Below is the code to search for an event

void SearchingEvent(const char* date){
    FILE *file = fopen ("events.txt", "r");
    char line[256];
    int found = 0;

    if(file == NULL){
        printf("Sorry! No event files found yet.\n");
        return;
    }

    while(fgets(line, sizeof(line), file)){
        char eventDate[11], eventDescription[200];

        if(sscanf(line, "%10[^|] | %199[^\n]", eventDate, eventDescription) == 2){
            if(strcmp(eventDate, date) == 0){
                printf("Event on %s: %s\n", eventDate, eventDescription);
                found = 1;
            }
        }
    }

    fclose(file);

    if(!found){
        printf("No events were found on %s.\n", date);
    }
}

// no need for main here because its just for getters and setter

// method for set daycode from user input 

// method for get daycode 

//method to change color of date on calendar 

// method for somthing i can't think of 



