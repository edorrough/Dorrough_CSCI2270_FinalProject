# Dorrough_CSCI2270_FinalProject

  PHASE 1

The most final of projects.
I am working on my final project alone.
I am making a program to assist me in recording and updating character sheets in the tabletop role playing game Dungeons and Dragons (D&D). D&D requires constant bookkeeping and editing of your character sheet due to abilities, spells, leveling up, and other modifiers, and sometimes it can be hard to keep up with the math on the fly. I wish to make a program that will keep track of my character or the characters in the party, but the program will not roll dice because, lets face it, nothing is satisfying like physically rolling a natural 20. This program could be described as a helper program designed to assist the players in playing, like keeping inventories clean and tidy, displaying attack modifiers, and doing math so the player doesn't have to.

  PHASE 2
  
Project Summary:
This program is an assistant to you for use during tabletop roleplaying games like Dungeons and Dragons 5th edition. It works by storing the character's values that are on your character sheet into a linked list, so that all of the different characters are connected and can be traversed from head to tail. Upon selecting a character to use, a menu will guide the user through the various operations he can perform on his character, including leveling up, gaining experience points, modifying ability scores, showing the stats of the character for quick reference, and limited die rolling. The program is designed to minimize the math done on the fly during a D&D session. Full functionality for finding, adding, deleting, and printing the characters stored in the linked list is included.

How to Run:
This program needs only the class interface, implementation, and driver file to run, similar to many of this semester's pervious assignments. Adding these three files to the same code::blocks project will work. Many of the prompts in the program are given by 'apostrophes' around the desired input, so typing out the words is necesarry. The menu system will guide you to where you desire to go, and the program can be quit at any time by typing 'quit'.
Upon loading up the program for the first time, create a new character by typing 'new'. It will prompt you for a name and a class. You can add nodes indefinitely with the add function, and the delete function can delete any node that was created. The print function lists all the characters stored in the linked list from head->tail. The select function is the biggest of them all, and will take you to another loop where menu choices prompt you for input. These choices in this loop are used to manipulate the selected character's stats. To quit out of this loop, type 'back'.

Dependencies:
Not many external applications or libraries are being used, except for the #include <time.h> and #include <stdlib.h>, and these were required for my program to use the rand() function effectively. Without using the time.h library to reset the seed of the rand() function every time it's needed, the rand() function would generate the same set of random numbers every time the program executed, which makes random die rolling quite impossible.
I also #incuded <iostream> to make use of the console.

System Requirements:
This was coded entirely on the CU Virtual Machine, on my Windows laptop. Tus, it will run on any other machine that has the CU VM on it.

Group Members:
Evan Dorrough,
Evan Dorrough, and
Evan Dorrough.

Contributors:
Tristan Townend - talked me through the framework of my project, offered advice on how to implement the data structure

Open Issues/Bugs:
Though I had inteded to implement it, I did not end up writing a save file functionality. The program loses all of its data every time it is closed, making the program of limited usefulness in its current form. Inputing wrong inputs also throws my program through a loop, making it possible to miss level-up bonuses and other important bits. The top priority for improving this project is writing to a file for every Character node in the linked list and saving that file.

  PHASE 3

