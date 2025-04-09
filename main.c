#include <stdio.h>

int main (void) {
    int year, leapyear;
    int *daycode;
    int menuChoice = 0;

    

    while(menuChoice != 3){
        printf("Option 1: Enter Event\nOption 2: Look up Event\nOption 3: Exit\n");
        printf("Enter an option ");
        scanf("%d", &menuChoice);

        if(menuChoice == 1){
            printf("Enter a day in the following form: 01/01/2001\n");
            scanf("%d", &daycode); //input daycode
        }
        else if(menuChoice == 2){
            printf("Enter day code in the following form: 01/01/2001\n");
            scanf("%d", &daycode); //get daycode 
        }
        else if(menuChoice != 3){
            printf("Invalid choice: please enter a valid choice\n");
        }
        
    }

    printf("Good bye!\n");

    return 0;
}