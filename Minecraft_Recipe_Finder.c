#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Minecraft_Recipe_Finder_linked-lists.h" //including linked-lists header file so the program can access the structs and functions located inside the header file

//hardcoded file path, replace when reviewing program
char recipeListPath[100] = ""; //input file path to recipes.txt in the quotation marks

void printMenu(void); //initializing the printMenu function

int main(void){
    char choice = 'i'; //Initializes the choice variable that stores the users choice to search for a recipe, add a recipe, or exit the program
    char recipeInput[100] = ""; //Initializes the recipeInput variable that stores the name of the item the user wants to search for
    while (choice != 'x'){ //As long as the user does not input 'x', the program will continue to print the menu
        printMenu(); //Prints the menu that will allow users to choose whether to search the database, add to the database, or exit the program
        scanf(" %c", &choice); //Stores the user's choice in the choice variable
        if (choice == 's'){
            /*
             If the user chooses to search the database, the program will ask for the user to input the name of the item they would like to craft
             It will then read the recipes.txt file into a linked list and search the list for the recipe the user would like to know
             */
            printf("(Please use hyphens instead of spaces when inputing the name of the item you wish to craft. For example: 'Crafting Table' should be 'Crafting-Table')\n");
            printf("What would you like to craft? ");
            scanf(" %s", recipeInput);
            readFile(recipeInput, recipeListPath);
        }else if (choice == 'a'){
            /*
             If the user chooses to add to the database, the program will ask the user to input the name of the item and all of the items needed to craft it
             It will then write the user's input to the recipes.txt file
             */
            char name[100] = "", L1[100] = "", M1[100] = "", R1[100] = "", L2[100] = "", M2[100] = "", R2[100] = "", L3[100] = "", M3[100] = "", R3[100] = "";
            printf("(Please use hyphens instead of spaces when inputing the names of the items. For example: 'Wood Planks' should be 'Wood-Planks')\n");
            printf("Please enter the information about what you would like to craft:\nName: ");
            scanf("%s", name);
            printf("L1: ");
            scanf("%s", L1);
            printf("M1: ");
            scanf("%s", M1);
            printf("R1: ");
            scanf("%s", R1);
            printf("L2: ");
            scanf("%s", L2);
            printf("M2: ");
            scanf("%s", M2);
            printf("R2: ");
            scanf("%s", R2);
            printf("L3: ");
            scanf("%s", L3);
            printf("M3: ");
            scanf("%s", M3);
            printf("R3: ");
            scanf("%s", R3);
            
            writeFile(name, L1, M1, R1, L2, M2, R2, L3, M3, R3, recipeListPath);
        }
    }
    printf("Thank you for using the Minecraft recipe database!\n");
    return 0;
}

//Prints the menu that allows the user to choose whether they want to search for a recipe, add to the database, or exit the program
void printMenu(void){
    printf("s - search for recipe\n");
    printf("a - add to recipe database\n");
    printf("x - exit\n");
    printf("Choice> ");
}
