**README**

_Project Members:_

Katie and Sahar

---
---
### Project Details:
This code creates a calender that will visualize in the console. The code consists of an array that stores the number of days in a month. It also has loops to check the day code to figure out the month and what date and day the month starts at to print that specific month into the terminal. 

Since we are using header files, to compile use this command in the terminal:

--> gcc main.c events.c calendar.c -o main

--> ./a.out

---
### SnapShots of some code below:

```ruby
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
        printf("%4d", day);

        if((day + dayCode) % 7 == 0){
            printf("\n");
        }
    }

    printf("\n");
}
```

There will be certain functions that will read and store event input into memory to be called upon. These two functions do exactly that. The AddingEvent function will open the txt file to add and store the event data (user description) into a specific date to be called upon. 

---

Below is the code for function that adds an event to the calendar:
```ruby
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
```

---
Below is the code for a fucntion that searchs an event stored in the calendar. The SearchingEvent function will literally search and match the date in the event stored in the txt file and print out the event description with the date. If no events are found on that date the program will print out "No events found".
```ruby
void SearchingEvent(const char* date){
    FILE *file = fopen ("events.txt", "r");
    char line[256];
    int found = 0;

    //if user enter a date that isn't on file; error message will be shown 
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
```
---

**--Notes:**

This program includes the followwing files:
1. main.c
2. calendar.c
3. events.c

header files:
1. calendar.h
2. events.h

