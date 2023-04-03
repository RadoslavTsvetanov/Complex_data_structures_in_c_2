#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char firstname[50];
    struct node *father;
    struct node *mother;
    struct node *marriedto;
} Node;
int main()
{
    // Create family tree
    Node *grandfather = (Node *)malloc(sizeof(Node));
    strcpy(grandfather->firstname, "Stoil");
    grandfather->father = NULL;
    grandfather->mother = NULL;
    grandfather->marriedto = NULL;

    Node *grandmother = (Node *)malloc(sizeof(Node));
    strcpy(grandmother->firstname, "Maria");
    grandmother->father = NULL;
    grandmother->mother = NULL;
    grandmother->marriedto = grandfather;

    Node *father = (Node *)malloc(sizeof(Node));
    strcpy(father->firstname, "Anton");
    father->father = grandfather;
    father->mother = grandmother;
    father->marriedto = NULL;

    Node *mother = (Node *)malloc(sizeof(Node));
    strcpy(mother->firstname, "Hrisi");
    mother->father = NULL;
    mother->mother = NULL;
    mother->marriedto = father;

    Node *me = (Node *)malloc(sizeof(Node));
    strcpy(me->firstname, "Radoslav");
    me->father = father;
    me->mother = mother;
    me->marriedto = NULL;

    // Print family tree
    printf("Grandfather: %s\n", grandfather->firstname);
    printf("Grandmother: %s\n", grandmother->firstname);
    printf("Father: %s, Father's father: %s, Father's mother: %s\n", father->firstname, father->father->firstname, father->mother->firstname);
    printf("Mother: %s\n", mother->firstname);
    printf("Me: %s, My father: %s, My mother: %s\n", me->firstname, me->father->firstname, me->mother->firstname);

    // Free memory
    free(grandfather);
    free(grandmother);
    free(father);
    free(mother);
    free(me);

    return 0;
}