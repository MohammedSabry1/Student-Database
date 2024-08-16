#include <stdio.h>
#include "SDB.h"
#include "STD.h"
uint16 choice;                       // choise of user
uint32 id;                           // the id which user will enter
uint8 count;                         // the adrees which will be passed to the getlist fun
uint32 list[MAX_NUMBER_OF_STUDENTS]; // arry of max num of students

void SDB_action(uint8 choice) // the function to the choise from the user
{
    if (choice == 1) // check if choise is number 1
    {
        SDB_AddEntry(); // call the function SDB_AddEntry();
    }
    else if (choice == 2) // check if choise is number 2
    {
        SDB_GetUsedSize(); // call the function SDB_GetUsedSize();
    }
    else if (choice == 3) // check if choise is number 3
    {
        printf("Enter Student ID to read: ");
        scanf("%d", &id); // scan the id from the user

        if (SDB_IsIdExist(id)) // check if the id is exist
        {
            SDB_ReadEntry(id); // if exist call the function  SDB_ReadEntry(id);
        }
        else
        {
            printf("Student with ID %d does not exist.\n", id); // if not exist printf not exist
        }
    }
    else if (choice == 4) // check if choise is number 4
    {
        SDB_GetList(&count, list); // pass adress of count and array called list
        printf("Student IDs: ");
        for (uint8 i = 0; i < count; i++) // looping the db and printing the ids
        {
            printf("%d ", list[i]);
        }
    }
    else if (choice == 5) // check if choise is number 5
    {
        {
            printf("Enter Student ID to check: ");
            scanf("%d", &id);      // scan the id from the user
            if (SDB_IsIdExist(id)) // check if the id is exist
            {
                printf("Student with ID %d exists.\n", id); // if exist printf exist;
            }
            else
            {
                printf("Student with ID %d does not exist.\n", id); // if not exist printf not exist;
            }
        }
    }
    else if (choice == 6) // check if choise is number 6
    {
        printf("Enter Student ID to delete: ");
        scanf("%d", &id);      // scan the id from the user
        if (SDB_IsIdExist(id)) // check if the id is exist
        {
            SDB_DeletEntry(id); // if exist call the function SDB_DeletEntry(id);
            printf("Student with ID %d was deleted.\n", id);
        }
        else
        {
            printf("Student with ID %d does not exist.\n", id);
        }
    }
    else if (choice == 7) // check if choise is number 7
    {
        SDB_IsFull(); // call the function SDB_IsFull();
    }
    else // if other choise printf unvalid choise
    {
        printf("unvalid choice");
    }
}
void SDB_APP()
{

    while (1) // super loop to allow user use the program unlimited as it always be true
    {
        printf("\n1. Add entry\n");
        printf("2. Get used size\n");
        printf("3. Read student data\n");
        printf("4. Get list of student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete entry\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // scan the chose of the user
        if (choice == 0)      // check if the choise = 0 break out of the program
            break;
        SDB_action(choice); // pass the choise to function  SDB_action(choice)
    }
}