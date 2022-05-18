//
//  main.c
//  officeSpaceAllocation
//
//  Created by Clement  Wekesa on 06/05/2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    bool appRunning = true;
    char inputString[100];
    char end[] = "q";
    
    enum commands {create_room=1, add_person};
    enum roomType {office=1, accomodation};
    enum personGroup {staff=1, fellow};
    
    struct Room {
        char name[50];
        int capacity;
        enum roomType type;
    };
    
    struct Person {
        char name[50];
        enum personGroup group;
        bool takingAccomodation;
    };

    while (appRunning) {
        char lstCom[10][100];
        int lstind = 0;
        
        printf("Enter your command: \n");
        fgets(inputString, 100, stdin);
        size_t stringLen = strlen(inputString);
        if ((int) inputString[stringLen - 1] == 10) {
            inputString[stringLen - 1] = '\0';
        }
        char *token = strtok(inputString, " ");
        // Split the string to words
        while (token != NULL) {
            size_t tokenLen = strlen(token);
            for (int i = 0; i < tokenLen; i++) {
                lstCom[lstind][i] = token[i];
            }
            token = strtok(NULL, " ");
            lstind++;
        }

        if (strcmp("create_room", lstCom[0]) == 0) {
            printf("you have entered create_room command:-) ");
        } else if(strcmp("add_person", lstCom[0]) == 0) {
            printf("you have entered add_person command");
        }
        
        // This is where we terminate the program
        if (strcmp(inputString, end) == 0) {
            appRunning = false;
        }
    }
    return 0;
}
