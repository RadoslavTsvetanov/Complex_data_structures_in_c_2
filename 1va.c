#include <stdio.h>

#define MAX_PARTICIPANTS 100

typedef struct
{
    int day;
    int month;
    int year;
    struct
    {
        int hour;
        int minute;
    };
} Date;

typedef struct
{
    char title[100];
    char description[500];
    Date date;
    struct
    {
        char first_name[50];
        char middle_name[50];
        char last_name[50];
        char email[100];
        char phone[20];
    } participants[MAX_PARTICIPANTS];
    struct
    {
        int participant_index;
        int is_attending;
    } responses[MAX_PARTICIPANTS];
} Cause;

int main()
{
    Cause cause1 = {
        .title = "Beach cleanup",
        .description = "Cleaning up the beach and the nearby park",
        .date = {10, 5, 2023, {9, 0}},
        .participants = {
            {"John", "Smith", "", "john.smith@gmail.com", "555-1234"},
            {"Emily", "Brown", "", "emily.brown@yahoo.com", "555-5678"},
            {"David", "Lee", "", "david.lee@hotmail.com", "555-2468"}}};

    Cause cause2 = {
        .title = "Fundraiser",
        .description = "Help us raise money for a good cause!",
        .date = {5, 7, 2023, {15, 0}},
        .participants = {
            [0] = {"Alice Brown", "alice.brown@gmail.com", "555-1111", 1},
            [1] = {"Tom Wilson", "tom.wilson@gmail.com", "555-2222", 0},
            [2] = {"Sara Jones", "sara.jones@gmail.com", "555-3333", 1},
        }};

    Cause cause3 = {
        .title = "help me learn C",
        .description = "Helping me learn this alwfully hard language",
        .date = {15, 6, 2023, {10, 30}},
        .participants = {
            {"Bozhidar", "Johnson", "Dimitrov", "Bozhidar.Dimitrov@gmail.com", "555-7890"},
            {"Michael", "Davis", "", "michael.davis@yahoo.com", "555-4321"}}};

    printf("Cause 1:\n");
    printf("Title: %s\n", cause1.title);
    printf("Description: %s\n", cause1.description);
    printf("Date: %d/%d/%d at %02d:%02d\n", cause1.date.day, cause1.date.month, cause1.date.year, cause1.date.hour, cause1.date.minute);
    printf("Participants:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s (%s, %s) - %s\n", cause1.participants[i].first_name, cause1.participants[i].email, cause1.participants[i].phone, cause1.responses->is_attending ? "attending" : "not attending");
    }

    return 0;
}