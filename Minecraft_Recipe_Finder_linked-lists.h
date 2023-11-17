#ifndef linked_lists_h
#define linked_lists_h

#include <stdio.h>

#endif /* linked_lists_h */

struct recipe_struct{ //creates the struct for the recipes which include the name of the item and the names of all of the items needed to craft it
    char name[100];
    char L1[100];
    char M1[100];
    char R1[100];
    char L2[100];
    char M2[100];
    char R2[100];
    char L3[100];
    char M3[100];
    char R3[100];
    struct recipe_struct *next; //creates pointer used in creating a linked list
};

typedef struct recipe_struct recipeRecord; //defines the struct as recipeRecord so it is easier to refer to it

struct recipeList_struct{ //creates the structure for the linked list used to store all of the recipes
    recipeRecord* head;
};

typedef struct recipeList_struct recipeList; //defines the struct as recipeList so it is easier to refer to it


//Initializes all of the funtions in the linked-lists.c file
recipeRecord* new_recipeRecord(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*);
void disposeRecord(recipeRecord*);
recipeList* new_recipeList(void);
void disposeList(recipeList*);
void recipeList_add(recipeList*, recipeRecord*);
void readFile(char*, char*);
void printList(recipeList*);
recipeRecord* findRecipe(recipeList*, char*);
void printRecord(recipeRecord*);
void writeFile(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*, char*);



