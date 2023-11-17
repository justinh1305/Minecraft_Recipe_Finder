# Minecraft_Recipe_Finder
This program allows users to find a crafting recipe on Minecraft by inputting the name of the item they would like to craft.
It utilizes linked lists and file pointers to store and manage the crafting recipes in a database stored on a plain text file (recipes.txt)
If the users need a recipe that is not found in the database (for example, maybe Minecraft added new recipes to the game) then users can also add to the database by inputting the name of the item they would like to add followed by the items needed to craft it.

Notes for running the program:
1. Please input the path to the recipes.txt file in the global variable recipeListPath found in the Minecraft_Recipe_Finder.c file
2. When inputting an item name, you must use hyphens instead of spaces and capitalize every word in the item name (for example, "Crafting table" should be "Crafting-Table")
3. L = Left Column, M = Middle Column, R = Right Column - 1 = Top Row, 2 = Middle Row, 3 = Right Row
   
![Crafting Table example](https://github.com/justinh1305/Minecraft_Recipe_Finder/assets/145511867/5f1fff64-ec74-4264-be25-db37fdfda3fc)
