#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Minecraft_Recipe_Finder_linked-lists.h" //includes linked lists header file which stores the structs needed for the functions in this file

//Function that allocates memory for a new record that may be added to the linked list
recipeRecord* new_recipeRecord(char* name, char* L1, char* M1, char* R1, char* L2, char* M2, char* R2, char* L3, char* M3, char* R3){
    recipeRecord* newRecord = (recipeRecord*)malloc(sizeof(recipeRecord)); //allocates the correct amount of memory for the new record
    
    //assigns the values of each entry in the record, includes the name of the item the user wants to craft and the items needed to craft it
    strcpy(newRecord->name, name);
    strcpy(newRecord->L1, L1);
    strcpy(newRecord->M1, M1);
    strcpy(newRecord->R1, R1);
    strcpy(newRecord->L2, L2);
    strcpy(newRecord->M2, M2);
    strcpy(newRecord->R2, R2);
    strcpy(newRecord->L3, L3);
    strcpy(newRecord->M3, M3);
    strcpy(newRecord->R3, R3);
    
    return newRecord; //returns the record with all the information
}

//function to free a given record
void disposeRecord(recipeRecord* delRecord){
    free(delRecord);
}

//function that creates the linked list
recipeList* new_recipeList(void){
    recipeList* newList = (recipeList*)malloc(sizeof(recipeList)); //allocates the correct amount of memory for the linked list
    
    newList->head = NULL;
    
    return newList; //returns the newly created linked list
}

//function that frees all of the records in the linked list, effectively freeing all of the memory allocated for the linked list
void disposeList(recipeList* delList){
    recipeRecord *next;
    while(delList->head != NULL){
        next = delList->head->next;
        disposeRecord(delList->head);
        delList->head = next;
    }
    free(delList);
}

//function that adds a record to the linked list, it will add the new record to the head of the linked list
void recipeList_add(recipeList* rl, recipeRecord* recipe){
    recipe->next = rl->head;
    rl->head = recipe;
}

//Function that reads the recipes.txt file, creates a linked list from it, and prints the crafting recipe of the item the user wants to craft
void readFile(char *input, char *filename){
    recipeList* rl = new_recipeList(); //creates a new recipe linked list
    
    //creates a file pointer and opens the recipes.txt file in read mode
    FILE *fp;
    fp = fopen(filename, "r");
    if(!fp){ //if the file does not open, the program will print a read error and return
        printf("read err\n");
        return ;
    }
    
    //creates variables to hold the name of each item and all of the items that are needed to craft them
    char name[100] = "", L1[100] = "", M1[100] = "", R1[100] = "", L2[100] = "", M2[100] = "", R2[100] = "", L3[100] = "", M3[100] = "", R3[100] = "";
    char line[1000] = ""; //creates a variable that holds a line in the recipes.txt file
    
    /*
     while the program does not reach the end of the recipes.txt file, it will save the line to the line variable and
     populate the values of name, L1, M1, R1, L2, M2, R2, L3, M3, and R3 with the strings found in the line
     it will then create a new record based on all the variables and add the record to the recordList rl
     */
    while(!feof(fp)){
        fscanf(fp, "%[^\n] s", line);
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", name, L1, M1, R1, L2, M2, R2, L3, M3, R3);
        recipeRecord *record = new_recipeRecord(name, L1, M1, R1, L2, M2, R2, L3, M3, R3);
        recipeList_add(rl, record);
    }
    
    recipeRecord* findRecord; //creates the recipeRecord pointer that will be used to find the recipe of the item the user wants to craft
    findRecord = findRecipe(rl, input); //uses the findRecipe function to populate the findRecord pointer with the record of the item
    
    //if the findRecord pointer is NULL, the program will print out a record error and return
    if (findRecord == NULL){
        printf("record error\nRecipe may not be in database\n");
        return;
    }
    printRecord(findRecord); //prints the recipe of the item the user wants to craft
    
    //frees all allocated memory and closes the recipes.txt file
    disposeList(rl);
    fclose(fp);
    return;
}

//function that prints the recipeList, used for debugging
void printList(recipeList* rl){
    recipeRecord* record = rl->head;
    while (record != NULL){
        printf("Name: %s\n", record->name);
        printf("L1: %s\n", record->L1);
        printf("M1: %s\n", record->M1);
        printf("R1: %s\n", record->R1);
        printf("L2: %s\n", record->L2);
        printf("M2: %s\n", record->M2);
        printf("R2: %s\n", record->R2);
        printf("L3: %s\n", record->L3);
        printf("M3: %s\n", record->M3);
        printf("R3: %s\n", record->R3);
        record = record->next;
    }
}

//function used to print the record of the recipe of the item the user wants to craft
void printRecord(recipeRecord *recipe){
    printf("Name: %s\n", recipe->name);
    printf("L1: %s\n", recipe->L1);
    printf("M1: %s\n", recipe->M1);
    printf("R1: %s\n", recipe->R1);
    printf("L2: %s\n", recipe->L2);
    printf("M2: %s\n", recipe->M2);
    printf("R2: %s\n", recipe->R2);
    printf("L3: %s\n", recipe->L3);
    printf("M3: %s\n", recipe->M3);
    printf("R3: %s\n", recipe->R3);
}

//funtion used to find the record of the recipe of the item the user wants to craft by using the name of the item the user inputted
recipeRecord* findRecipe(recipeList *recipeDB, char *nameInput){
    recipeRecord* record = recipeDB->head;
    char *name;
    //the loop will parse through the linked list to find the recipeRecord with the same name as the name of the item the user inputted
    while(record != NULL){
        name = record->name;
        if (!(strcmp(nameInput, name))){
            return record;
        }
        record = record->next;
    }
    return NULL; //if the function does not find anything, it will return NULL
}


//function used to append recipes to the file
void writeFile(char *name, char *L1, char *M1, char *R1, char *L2, char *M2, char *R2,char *L3, char *M3, char *R3, char *filename){
    //creates file pointer and opens the recipes.txt file in append mode
    FILE *fp;
    fp = fopen(filename, "a");
    
    //if the file does not open, the program will print an error and return
    if (fp == NULL){
        printf("write open err\n");
        return;
    }
    
    //prints the name, L1, M1, R1, L2, M2, R2, L3, M3, and R3 values to the recipes.txt file
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,", name, L1, M1, R1, L2, M2, R2, L3, M3, R3);
    //closes the recipes.txt file
    fclose(fp);
}
