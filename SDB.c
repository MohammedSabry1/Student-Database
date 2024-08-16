#include <stdio.h>
#include "SDB.h"
#include "STD.h"
uint32 CURRENT_SIZE_OF_DB = 0;
student database[MAX_NUMBER_OF_STUDENTS];

int bubble_sort(student *ptr, int size) // this function to sort the arry elements==> it takes arry and size of array
{
    student temp;                  // temp var to save the struct element
    for (int i = 0; i < size; i++) // first loop to set the largest elment at the end
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ptr[j].Student_ID > ptr[j + 1].Student_ID)
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
    for (int z = 0; z < size; z++)
    {
        printf("%d\t", ptr[z].Student_ID);
    }
}

bool_ SDB_IsFull() // this function check if the database is full by compareing the current size with max size
{
    if (CURRENT_SIZE_OF_DB == MAX_NUMBER_OF_STUDENTS)
    {
        printf("Database is full");

        return true_; // return true if full
    }
    else
    {
        printf("Database is not full");

        return false_; // return false if  not full
    }
}

uint8 SDB_GetUsedSize() // get the current size of database after adding new student the current size will increase by 1 max of 10
{
    printf("Current size of db is:%d\n", CURRENT_SIZE_OF_DB);
    return CURRENT_SIZE_OF_DB; // retuen current size
}

void SDB_DeletEntry(uint32 id) // to delete student information with id
{
    for (int i = 0; i < CURRENT_SIZE_OF_DB; i++)
    {
        if (id == database[i].Student_ID) // check if id exist
        {
            for (int j = i; j < CURRENT_SIZE_OF_DB - 1; j++) // shift the elements of db
            {
                database[j] = database[j + 1];
            }
            CURRENT_SIZE_OF_DB--;                      // reduce size of database
            bubble_sort(database, CURRENT_SIZE_OF_DB); // sort the database again
        }
    }
}
bool_ SDB_ReadEntry(uint32 id) // to give information of student with id
{

    for (int i = 0; i < CURRENT_SIZE_OF_DB; i++)
    {

        if (id == database[i].Student_ID) // check if id is exist and send its information
        {
            printf("Student ID:%d\n", database[i].Student_ID);
            printf("Student year:%d\n", database[i].Student_year);
            printf("Student Course 1 ID:%d\n", database[i].Course1_ID);
            printf("Student Course 1 grade::%d\n", database[i].Course1_grade);
            printf("Student Course 2 ID:%d\n", database[i].Course2_ID);
            printf("Student Course 2 grade::%d\n", database[i].Course2_grade);
            printf("Student Course 3 ID:%d\n", database[i].Course3_ID);
            printf("Student Course 3 grade::%d\n", database[i].Course3_grade);
            return true_; // return true if student exist
        }
    }
    return false_; // return false if student does not exist
}
void SDB_GetList(uint8 *count, uint32 *list) // this function to get the ids saved on database
{
    *count = CURRENT_SIZE_OF_DB; // set the value pointed to by count to the current size of db
    for (int i = 0; i < CURRENT_SIZE_OF_DB; i++)
    {
        list[i] = database[i].Student_ID; // save the stds ids in the array list[i]
    }
}
bool_ SDB_IsIdExist(uint32 id) // check if student exist
{
    for (int i = 0; i < CURRENT_SIZE_OF_DB; i++)
    {
        if (id == database[i].Student_ID) // check if id is exist in db
        {
            return true_; // return 1 if exist
        }
    }
    return false_; // return 0 if it does not exist
}
bool_ SDB_AddEntry() // this function is used to add new student to data base and save ii in the arry of struct
{
    student SDB_new_student;
    if (SDB_IsFull()) // check if data base is full
    {
        printf("Database is full\n");
        return true_; // return true
    }

    printf("Enter Student ID: ");
    scanf("%d", &SDB_new_student.Student_ID);      // scan the id of student
    if (SDB_IsIdExist(SDB_new_student.Student_ID)) // check if the id already exist
    {
        printf("This Student already exists\n");
        return false_;
    }

    printf("Enter Student year: ");
    scanf("%d", &SDB_new_student.Student_year); // scan student informations
    printf("Enter Course 1 ID: ");
    scanf("%d", &SDB_new_student.Course1_ID); // scan student informations
    printf("Enter Course 1 grade: ");
    scanf("%d", &SDB_new_student.Course1_grade); // scan student informations
    printf("Enter Course 2 ID: ");
    scanf("%d", &SDB_new_student.Course2_ID); // scan student informations
    printf("Enter Course 2 grade: ");
    scanf("%d", &SDB_new_student.Course2_grade); // scan student informations
    printf("Enter Course 3 ID: ");
    scanf("%d", &SDB_new_student.Course3_ID); // scan student informations
    printf("Enter Course 3 grade: ");
    scanf("%d", &SDB_new_student.Course3_grade);        // scan student informations
    CURRENT_SIZE_OF_DB++;                               // increase the sizze of db by 1
    database[CURRENT_SIZE_OF_DB - 1] = SDB_new_student; // add the new student to the new place of array -1 to save the data in right position
    return true_;                                       // return true if saved success
}