#ifndef EVENTS_H 
#define EVENTS_H
#define MAX_EVENTS 100

//loads all the event dates from the file into memory
void LoadEventDates(void);

//checks for events on a specific date 
int HasEvent(int month, int day, int year);

//adds a new event into the txt file
void AddingEvent(const char* date, const char* description);

//search for an event on a specific day 
void SearchingEvent(const char* date);

#endif 

//Had to do research on how to add this header file 


