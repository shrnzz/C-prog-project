#include <stdio.h>
#include <string.h>
#define MAX_EVENTS 100
/*
events from user input will be saved into the events.txt file in the 
following format:

MM/DD/YY | Brunch with friends at 1pm.

*/

//Below is the code to add an event
//structure that defines the array of char with size 11
typedef struct{
    char date[11];
} Event;

Event eventList[MAX_EVENTS];
int eventCount = 0;

//function to open and close the text file to save the inputed events 
void LoadEventDates(){
    FILE *file =fopen("events.txt", "r");
    char line[256];

    eventCount = 0;

    if (file == NULL){
        
        return;
    }
    //looks through the events until i finds a match otherwise prints nothing 
    while (fgets(line, sizeof(line), file) && eventCount < MAX_EVENTS) {
        char eventDate[11];

        if(sscanf(line, "%10[^|]", eventDate) == 1){
            strncpy(eventList[eventCount].date, eventDate, 11);
            eventList[eventCount].date[10] = '\0';
            eventCount++;
        }
    }

    fclose(file);
}

//function to check if there is an event on a specific date base on the day code
int HasEvent(int month, int day, int year){
    char date[11];
    snprintf(date, sizeof(date), "%02d/%02d/%04d", month, day, year);

    for(int i = 0; i < eventCount; i++){
        if (strcmp(eventList[i].date, date) == 0){
            return 1;
        }
    }

    return 0;
}

//function to add an event to the txt file and prints event is saved
void AddingEvent(const char* date, const char* description) {
    FILE *file = fopen ("events.txt", "a");  //this is for append mode

    if(!file){
        printf("File-Error!\n Unable to open events file.\n");
        return;
    }
    //the format of how the event is saved in the txt file 
    fprintf(file, "%s | %s\n", date, description);
    fclose(file);
    printf("Event is saved!\n");
}

// Below is the code to search for an event
void SearchingEvent(const char* date){
    FILE *file = fopen ("events.txt", "r");
    char line[256];
    int found = 0;

    //if user enter a date that isn't on file; error message will be shown 
    if(!file){
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





